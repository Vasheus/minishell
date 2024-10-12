/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:10:03 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/12 16:01:32 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    
    char *input;
    t_list *lst;
    t_list *tmp;
    set_args *arg;

    while (1)
    {
        input = readline("> ");
        if (input == NULL || ft_strcmp(input, "exit") == 0)
        {
            free(input);
            break;
        }

        lst = parsing(input);
        syntax(&lst);
        classing(&lst);
        
        arg = settingargs(&lst);

        tmp = lst;
        
        
        //PRINTING TOKENS AND TYPE OF COMMAND
        while (tmp)
        {
            printf("Token: %s, Type: %u\n", (char *)tmp->content, tmp->command);
            tmp = tmp->next;
        }
        
        
        printf("#########\n#########\n#########\n#########\n");
        
        
        set_args *current_args = arg;
        
        // PRINTING THE ARGUMENTS AND THE INPUT/OUTPUT FD
        while (current_args)
        {
            printf("Input: %d, Output: %d\n", current_args->input, current_args->output);
            if (current_args->args)
            {
                printf("Arguments: ");
                int i = 0;
                while (current_args->args[i] != NULL)
                {
                    printf("%s ", current_args->args[i]);
                    i++;
                }
                printf("\n");
            }
            current_args = current_args->next;
        }

        free(input);
        ft_lstclear(&lst, free);
    }

    return 0;
}