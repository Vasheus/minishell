/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofred.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:11:35 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/10 14:54:00 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void handle_redirections(t_list *token, set_args *cmd_args)
{
    cmd_args->input = 0;
    cmd_args->output = 1;
    if(token->command == RD_OUT)
        cmd_args->output = open(token->next->content, O_CREAT | O_WRONLY | O_TRUNC, 644);
    else if(token->command == RD_IN)
        cmd_args->input = open(token->next->content, O_RDONLY);
    else if(token->command == APPEND)
        cmd_args->output = open(token->next->content, O_CREAT | O_WRONLY | O_APPEND, 644);
    else if (token->command == HEREDOC)
        cmd_args->output = create_unique_heredoc_file();
    
}

set_args *settingargs(t_list **lst, set_args *cmd_args)
{
    t_list *current;
    int     i;
    
    current = *lst;
    i = 0;
    while(current)
    {
        if(current->command == SPACE)
            current = current->next;
        else if(current->command == WORD || current->command == S_QUOTE
                || current->command == D_QUOTE)
        {
            cmd_args->args[i] = current->content;
            i++;
        }
        else if(current->command == VAR)
        {
            cmd_args->args[i] = get_var_value(current->content);
            i++;
        }
        else if(current->command == RD_IN || current->command == RD_OUT
            || current->command == APPEND || current->command == HEREDOC)
            handle_redirections(current, cmd_args);
        current = current->next;
    }
    return(cmd_args);
}
