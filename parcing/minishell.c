/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:10:03 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/02 16:03:31 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    char    *input;
    t_list  *lst;
    t_list  *tmp;

    while (1)
    {
        input = readline("> ");
        if (input == NULL || ft_strncmp(input, "exit", 4) == 0)
        {
            free(input);
            break;
        }

        lst = parsing(input);
        syntax(&lst);
        classing(&lst);

        tmp = lst;
        while (tmp)
        {
            printf("Token: %s, Type: %s\n", (char *)tmp->content, tmp->type);
            tmp = tmp->next;
        }

        free(input);
        ft_lstclear(&lst, free);
    }

    return 0;
}