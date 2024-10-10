/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settinglist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:44:50 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/10 16:47:16 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

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