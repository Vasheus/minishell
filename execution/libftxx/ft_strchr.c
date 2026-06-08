/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:18:43 by ael-garr          #+#    #+#             */
/*   Updated: 2023/12/14 21:01:21 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
