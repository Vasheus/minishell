/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:07:04 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/01 14:57:57 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"  // "space" "" '' $ | > < >> << \t

static void	handle_single_char(char *str, int i, t_list **lst)
{
	t_list	*new_node;

	new_node = ft_lstnew(ft_substr(str, i, 1));
	if (str[i] == '|')
		new_node->type = "pipe";
	else if (str[i] == '<')
		new_node->type = "rd_in";
	else if (str[i] == '>')
		new_node->type = "rd_out";
	ft_lstadd_back(lst, new_node);
}

static int	parse_operator(char *str, int i, t_list **lst)
{
	t_list	*new_node;
	// printf("---OPERATOR---");
	if (str[i] == '<' && str[i + 1] == '<')
	{
		new_node = ft_lstnew(ft_substr(str, i, 2));
		new_node->type = "heredoc";
		ft_lstadd_back(lst, new_node);
		i++;
	}
	else if (str[i] == '>' && str[i + 1] == '>')
	{
		new_node = ft_lstnew(ft_substr(str, i, 2));
		new_node->type = "append";
		ft_lstadd_back(lst, new_node);
		i++;
	}
	else
	{
		new_node = NULL;
		handle_single_char(str, i, lst);
	}
	return (i);
}

static int	parse_variable(char *str, int i, t_list **lst)
{
	t_list	*new_node;
	int		k;

	k = i;
	i++;

	if (str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
	{
		while (str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != '\'' && str[i] != '"')
			i++;
		new_node = ft_lstnew(ft_substr(str, k, i - k));
		new_node->type = "var";
		ft_lstadd_back(lst, new_node);
	}
	else
		return k;

	return i;
}

static int	parse_quote(char *str, int i, t_list **lst, char quote_type)
{
	t_list	*new_node;
	int		k;

	k = i;
	i++;
	while (str[i] && str[i] != quote_type)
		i++;
	new_node = ft_lstnew(ft_substr(str, k, i - k + 1));
	if (quote_type == '\'')
		new_node->type = "s_quote";
	else
		new_node->type = "d_quote";
	ft_lstadd_back(lst, new_node);
	return i;
}

t_list	*parsing(char *str)
{
	t_list	*lst;
	int		i;
	
	i = 0;
	lst = NULL;
	while (str[i])
    {
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
            i = parse_operator(str, i, &lst);
        else if (str[i] == '$')
            i = parse_variable(str, i, &lst);
        else if (str[i] == '\'' || str[i] == '"')
            i = parse_quote(str, i, &lst, str[i]);
        else if (str[i] == ' ' || str[i] == '\t')
            i = parse_spaces(str, i, &lst);
		else
            i = parse_word(str, i, &lst);
        i++;
    }
    return lst;
}
