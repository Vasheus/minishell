/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:46:17 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/12 19:47:57 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int is_space(t_list *token)
{
    return (token && (token->command == SPACEE));
}

int check_redirection_followed_by_pipe(t_list *current)
{
    t_list *next_token;
    
    next_token = current->next;

    while (is_space(next_token))
        next_token = next_token->next;

    if (next_token && (next_token->command == PIPE))
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

    if (next_token && ft_strcmp(next_token->content, "|") == 0)
        return (1);
    
    if (!next_token)
        return (1);
    return (0);
}
int syntax_quotes(t_list **lst)
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
    if (syntax_consecutive_redirection(lst) || syntax_end_of_command(lst) 
        || syntax_quotes(lst) || syntax_redpipe(lst))
        return (error_message(1), 1);
    return (0);
}
