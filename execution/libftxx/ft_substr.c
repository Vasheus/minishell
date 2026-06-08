/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:01:23 by ael-garr          #+#    #+#             */
/*   Updated: 2023/11/18 16:25:16 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	counter;
	char			*ptr;

	counter = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen((char *)s) || len == 0)
		return (ft_strdup(""));
	if (len + start > (ft_strlen((char *)s)))
		return (ft_strdup(&s[start]));
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[start] != '\0' && counter < len)
	{
		ptr[counter] = s[start];
		start++;
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
