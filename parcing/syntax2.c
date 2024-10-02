/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:46:17 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/02 16:03:01 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_space(t_list *token)
{
    return (token && ft_strncmp(token->type, "space", 5) == 0);
}

int check_redirection_followed_by_pipe(t_list *current)
{
    t_list *next_token;
    
    next_token = current->next;

    while (is_space(next_token))
        next_token = next_token->next;

    if (next_token && ft_strncmp(next_token->type, "pipe", 4) == 0)
        return (1);
    if (!next_token)
        return (1);
    return (0);
}

int check_consecutive_pipes(t_list *current)
{
    t_list *next_token;
    
    next_token = current->next;

    while (is_space(next_token))
        next_token = next_token->next;

    if (next_token && ft_strncmp(next_token->content, "|", 1) == 0)
        return (1);
    
    if (!next_token)
        return (1);
    return (0);
}
int syntax4(t_list **lst)
{
    t_list *current = *lst;
    char *str;
    int single_quote_open = 0;
    int double_quote_open = 0;

    while (current)
    {
        str = current->content;
        while (*str)
        {
            if (*str == '\'' && !double_quote_open)
                single_quote_open = !single_quote_open;
            else if (*str == '"' && !single_quote_open)
                double_quote_open = !double_quote_open;

            str++;
        }
        current = current->next;
    }
    if (single_quote_open || double_quote_open)
        return (1);
    return (0);
}
int syntax(t_list **lst)
{
    if (syntax1(lst) || syntax2(lst) || syntax3(lst) || syntax4(lst))
        error_message(1);
    return (0);
}
