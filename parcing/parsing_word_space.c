/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_word_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:57:00 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/12 17:36:04 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int parse_word(char *str, int i, t_list **lst)
{
    t_list *new_node;
    int k;
    
    k = i;
    while (str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != '\'' && str[i] != '"')
        i++;

    if (i > k)
    {
        new_node = ft_lstnew(ft_substr(str, k, i - k));
        new_node->command = WORD;
        ft_lstadd_back(lst, new_node);
    }
    return i - 1;
}

int parse_spaces(char *str, int i, t_list **lst)
{
    t_list *new_node;

    new_node = ft_lstnew(ft_substr(str, i, 1));
    new_node->command = SPACEE;
    
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    ft_lstadd_back(lst, new_node);
    return i - 1;
}
