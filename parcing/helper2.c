/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:42:22 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/10 16:02:44 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

static	int	lenint(int number)
{
	long int	temp;
	int			count;

	temp = number;
	count = 0;
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	if (number < 0)
		return (count + 1);
	else
		return (count);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			index;
	long int	tmp;

	tmp = n;
	if (tmp < 0)
		tmp *= -1;
	index = lenint(n);
	ptr = (char *)malloc(lenint(n) + 1);
	if (!ptr)
		return (NULL);
	ptr[index] = '\0';
	index--;
	while (index >= 0)
	{
		ptr[index] = (tmp % 10) + 48;
		index--;
		tmp = tmp / 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (dst[j] && j < dstsize)
		j++;
	while (src[i] && i + j < dstsize - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (j + ft_strlen(src));
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = src;
	d = dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}