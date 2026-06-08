/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:14:05 by ael-garr          #+#    #+#             */
/*   Updated: 2023/11/30 18:30:17 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_index(const char *s1, const char	*set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != (const char *)0)
	{
		i++;
	}
	return (i);
}

static int	end_index(const char *s1, const char *set)
{
	int	j;

	j = ft_strlen(s1) - 1;
	while (j >= 0 && ft_strchr(set, s1[j]) != (const char *)0)
	{
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (s1 == NULL)
	{
		ptr = (ft_strdup(""));
		return (ptr);
	}
	else if (set == NULL)
	{
		ptr = (ft_strdup(s1));
		return (ptr);
	}
	start = start_index(s1, set);
	end = end_index(s1, set);
	if (start > end)
	{
		ptr = (ft_strdup(""));
		return (ptr);
	}
	ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}
