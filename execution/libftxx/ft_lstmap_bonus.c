/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:46:59 by ael-garr          #+#    #+#             */
/*   Updated: 2023/12/02 17:24:39 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		current = ft_lstnew(NULL);
		if (!current)
		{
			ft_lstclear (&head, del);
			return (NULL);
		}
		current->content = f(lst->content);
		ft_lstadd_back (&head, current);
		lst = lst->next;
	}
	return (head);
}
