/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:33:39 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/01 10:18:31 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *tmp;

    if (!lst || !new)
        return;
    if (!*lst)  // If the list is empty, make new node the head
    {
        *lst = new;
    }
    else
    {
        tmp = *lst;
        while (tmp->next)  // Traverse to the last node
            tmp = tmp->next;
        tmp->next = new;  // Link the new node at the end
    }
    new->next = NULL;  // Ensure the new node's next pointer is NULL
}
t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;  // Assign the content
    new_node->type = NULL;        // Initialize type (set it later)
    new_node->next = NULL;        // Always set next to NULL
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