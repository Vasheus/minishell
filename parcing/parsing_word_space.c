/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_word_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:57:00 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/01 12:40:56 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
        new_node->type = "word";
        ft_lstadd_back(lst, new_node);
    }
    return i - 1;
}

int parse_spaces(char *str, int i, t_list **lst)
{
    t_list *new_node;

    new_node = ft_lstnew(ft_substr(str, i, 1));
    new_node->type = "space";
    
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    ft_lstadd_back(lst, new_node);
    return i - 1;
}
