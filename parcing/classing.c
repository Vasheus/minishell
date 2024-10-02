/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:55:45 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/02 16:02:26 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int checking_command(t_list *token)
{
    return(token && ft_strncmp(token->content, "echo", 4) == 0
                    || ft_strncmp(token->content, "cd", 2) == 0
                    || ft_strncmp(token->content, "pwd", 3) == 0
                    || ft_strncmp(token->content, "export", 6) == 0
                    || ft_strncmp(token->content, "unset", 5) == 0
                    || ft_strncmp(token->content, "env", 3) == 0
                    || ft_strncmp(token->content, "exit", 4) == 0);
}


void classing(t_list **lst)
{
    t_list *current;

    current = *lst;

    while(current)
    {
        if(checking_command(current))
            current->command = "builtins";
        current = current->next;
    }
}