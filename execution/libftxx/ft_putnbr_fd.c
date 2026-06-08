/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:07:27 by ael-garr          #+#    #+#             */
/*   Updated: 2023/11/30 11:01:51 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar ('-', fd);
		ft_putchar('2', fd);
		ft_putnbr(147483648, fd);
	}
	else if (nb < 0)
	{
		ft_putchar ('-', fd);
		nb = -nb;
		ft_putnbr(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
	else
		ft_putchar(nb + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
		ft_putnbr(n, fd);
}
