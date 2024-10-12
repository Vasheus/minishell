/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settinglist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:44:50 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/12 16:49:06 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

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
static set_args *init_set_args(void)
{
    set_args *cmd_args;

    cmd_args = (set_args *)malloc(sizeof(set_args));
    if (!cmd_args)
        return (NULL);
    cmd_args->args = NULL;
    cmd_args->input = 0;
    cmd_args->output = 1;
    cmd_args->next = NULL;
    return (cmd_args);
}

static void link_set_args(set_args **last_args, set_args **args_list, set_args *new_cmd_args)
{
    if (*last_args)
        (*last_args)->next = new_cmd_args;
    else
        *args_list = new_cmd_args;
    *last_args = new_cmd_args;
}

set_args *settingargs(t_list **lst)
{
    t_list *current;
    set_args *args_list;
    set_args *last_args;
    int num_commands;
    int i;

    current = *lst;
    args_list = NULL;
    last_args = NULL;
    num_commands = pipe_counter(lst);
    i = 0;

    while (i < num_commands)
    {
        set_args *cmd_args;
        cmd_args = init_set_args();
        if (!cmd_args)
            return (NULL);
        link_set_args(&last_args, &args_list, cmd_args);
        storing_args(&current, cmd_args);
        if (current && current->command == PIPE)
            current = current->next;
        i++;
    }
    return (args_list);
}