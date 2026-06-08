/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:42:17 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/19 11:33:25 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_commands(set_args *list)
{
	while (list)
	{
		ft_free_table(&list->args);
		list = list->next;
	}
	
}

void	free_t_list(t_list *list)
{
	t_list	*lst;
	lst = list;
	while (lst)
	{
		free(lst->content);
		lst = lst->next;
	}
	
}
void c_collector(t_minishell *data)
{
	free_commands(data->commands);
	free_t_list(data->list);
}
