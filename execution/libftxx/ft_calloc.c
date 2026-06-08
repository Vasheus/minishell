/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:45:19 by ael-garr          #+#    #+#             */
/*   Updated: 2023/12/02 17:23:43 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (size >= 4294967295 && count >= 4294967295)
		return (NULL);
	ptr = malloc(count * size);
	i = 0;
	if (ptr == NULL)
		return (0);
	while (i < (count * size))
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return ((void *)ptr);
}
