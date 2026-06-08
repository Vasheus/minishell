/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:07:38 by ael-garr          #+#    #+#             */
/*   Updated: 2023/11/18 16:25:49 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tempdst;
	const char	*tempsrc;
	size_t		i;

	i = 0;
	tempdst = (char *)dst;
	tempsrc = (const char *)src;
	if ((!tempdst && !tempsrc))
		return (NULL);
	if (tempdst > tempsrc)
	{
		while (len-- > 0)
			tempdst[len] = tempsrc[len];
	}
	else
	{
		while (i < len)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	}
	return (dst);
}
