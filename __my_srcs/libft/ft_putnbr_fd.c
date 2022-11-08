/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:32:48 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 17:33:07 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(long nb, int fd)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbr_rec(nb / 10, fd);
		ft_putnbr_rec(nb % 10, fd);
	}
	else
	{
		c = '0' + nb;
		ft_putchar_fd(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_rec(ln * -1, fd);
	}
	else
		ft_putnbr_rec(n, fd);
}
