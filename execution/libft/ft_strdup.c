/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:11:17 by ael-garr          #+#    #+#             */
/*   Updated: 2024/09/20 16:55:46 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*to_dup;
	char	*result;
	int		len;
	int		i;

	to_dup = (char *)s1;
	len = ft_strlen(to_dup);
	result = (char *)malloc((len * sizeof(char)) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (to_dup[i] != '\0')
	{
		result[i] = to_dup[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
