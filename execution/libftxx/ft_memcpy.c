/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:53:09 by ael-garr          #+#    #+#             */
/*   Updated: 2023/12/02 20:31:29 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t	n)
{
	unsigned char	*tempdst;
	unsigned char	*tempsrc;
	size_t			i;

	if (!dst && !src)
		return (dst);
	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}