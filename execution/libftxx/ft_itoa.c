/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:01:14 by ael-garr          #+#    #+#             */
/*   Updated: 2023/11/28 14:00:45 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_after_comma(int n)
{
	return (n % 10);
}

static int	countdigits(int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	if (number > 0)
	{
		while (number != 0)
		{
			number = (number / 10);
			count++;
		}
	}
	if (number < 0)
	{
		while (number != 0)
		{
			number = (number / 10);
			count++;
		}
	}
	return (count);
}

static void	remplir(int nb_cases, long my_n, char *ptr)
{
	if (my_n >= 0)
	{
		ptr[nb_cases] = '\0';
		if (my_n == 0)
			ptr[0] = '0';
		while (my_n)
		{
			--nb_cases;
			ptr[nb_cases] = get_after_comma(my_n) + 48;
			my_n = my_n / 10;
		}
	}
	else if (my_n < 0)
	{
		ptr[nb_cases + 1] = '\0';
		my_n *= -1;
		ptr [0] = '-';
		while (my_n)
		{
			ptr[nb_cases] = get_after_comma(my_n) + 48;
			my_n = my_n / 10;
			nb_cases--;
		}
	}
}

char	*ft_itoa(int n)
{
	int		nb_cases;
	char	*ptr;
	int		my_n;

	ptr = NULL;
	my_n = n;
	nb_cases = countdigits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (my_n >= 0)
		ptr = (char *)malloc(nb_cases + 1);
	else if (my_n < 0)
		ptr = (char *)malloc(nb_cases + 2);
	if (!ptr)
		return (NULL);
	remplir (nb_cases, my_n, ptr);
	return (ptr);
}
