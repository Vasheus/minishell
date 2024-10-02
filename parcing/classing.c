/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:55:45 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/02 19:01:19 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

static int checking_command(t_list *token)
{
    return(token && (ft_strcmp(token->content, "echo") == 0
                    || ft_strcmp(token->content, "cd") == 0
                    || ft_strcmp(token->content, "pwd") == 0
                    || ft_strcmp(token->content, "export") == 0
                    || ft_strcmp(token->content, "unset") == 0
                    || ft_strcmp(token->content, "env") == 0
                    || ft_strcmp(token->content, "exit") == 0));
}


void classing(t_list **lst)
{
    t_list *current;

    current = *lst;

    while(current)
    {
        if(checking_command(current))
            current->type = BUILT_IN;
        else
            current->type = SIMPLE_COMMAND;
        current = current->next;
    }
}