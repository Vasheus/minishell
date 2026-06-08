/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:32:21 by ael-garr          #+#    #+#             */
/*   Updated: 2024/09/25 19:29:28 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_find_node(t_minishell *data, char	*str)
{
	char *local;
	t_environ *lst;
	
	local = NULL;
	lst =  data->env_lst;
	
	while (lst)
	{
		if (ft_strncmp(lst->var, str, (ft_strlen(lst->var) + 1)) == 0)
		{
			local = ft_strdup(lst->value);
			if (!local)	
				return (NULL);
			return(local);
		}
		lst = lst->next;
	}
	return (NULL);
}
