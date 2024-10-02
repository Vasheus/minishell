/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:33:39 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/02 19:01:34 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *tmp;

    if (!lst || !new)
        return;
    if (!*lst)
    {
        *lst = new;
    }
    else
    {
        tmp = *lst;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    new->next = NULL;
}
t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*x;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		x = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = x;
	}
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	(*del)(lst->content);
	free(lst);
}