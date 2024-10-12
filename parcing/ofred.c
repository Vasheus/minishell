/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofred.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:11:35 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/12 15:58:22 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int pipe_counter(t_list **lst)
{
    t_list *current;
    int     i;
    
    current = *lst;
    i = 0;
    while(current)
    {
        if(current->command == PIPE)
            i++;
        current = current->next;
    }
    return (i + 1);
}
void handle_redirections(t_list *token, set_args *cmd_args)
{
    cmd_args->input = 0;
    cmd_args->output = 1;
    if(token->command == RD_OUT)
    {
        if(cmd_args->output != 1)
            close(cmd_args->output);
        cmd_args->output = open(token->next->content, O_CREAT | O_WRONLY , 644);
    }
    else if(token->command == RD_IN)
        cmd_args->input = open(token->next->content, O_RDONLY);
    else if(token->command == APPEND)
    {
        if(cmd_args->output != 1)
            close(cmd_args->output);
        cmd_args->output = open(token->next->content, O_CREAT | O_WRONLY | O_APPEND, 644);
    }
    else if (token->command == HEREDOC)
        cmd_args->output = create_unique_heredoc_file();
    
}
void add_arg_to_set_args(set_args *cmd_args, char *new_arg)
{
    char **new_args;
    int count;
    int i;

    count = 0;
    i = 0;
    while (cmd_args->args && cmd_args->args[count])
        count++;
    new_args = (char **)malloc(sizeof(char *) * (count + 2));
    if (!new_args)
        return;

    while (i < count)
    {
        new_args[i] = cmd_args->args[i];
        i++;
    }
    new_args[count] = ft_strdup(new_arg);
    new_args[count + 1] = NULL;

    free(cmd_args->args);
    cmd_args->args = new_args;
}

void storing_args(t_list **current, set_args *cmd_args)
{
    while (*current && (*current)->command != PIPE)
    {
        if ((*current)->command == WORD || (*current)->command == S_QUOTE ||
            (*current)->command == D_QUOTE)
            add_arg_to_set_args(cmd_args, (*current)->content);
        else if ((*current)->command == VAR)
        {
            char *var_value;
            
            var_value = get_var_value((*current)->content);
            add_arg_to_set_args(cmd_args, var_value);
        }
        else if ((*current)->command == RD_IN || (*current)->command == RD_OUT ||
                 (*current)->command == APPEND || (*current)->command == HEREDOC)
            handle_redirections(*current, cmd_args);
        *current = (*current)->next;
    }
}

