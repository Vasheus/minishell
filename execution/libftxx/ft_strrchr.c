/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:02:34 by ael-garr          #+#    #+#             */
/*   Updated: 2023/11/20 16:56:53 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *chain, int c)
{
	char	*result;

	result = NULL;
	while (*chain)
	{
		if (*chain == (char)c)
			result = ((char *)chain);
		chain++;
	}
	if (*chain == (char)c)
		result = (char *)chain;
	return (result);
}
