/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:18:43 by ael-garr          #+#    #+#             */
/*   Updated: 2024/09/20 16:56:11 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strchr(const char *chain, int c)
{
	int	i;

	i = 0;
	while (chain[i] != '\0')
	{
		if (chain[i] == (char)c)
			return ((char *)&chain[i]);
		i++;
	}
	if (chain[i] == (char)c)
		return ((char *)&chain[i]);
	return (NULL);
}
