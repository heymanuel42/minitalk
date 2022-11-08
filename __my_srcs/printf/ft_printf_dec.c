/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:20:24 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/31 09:19:00 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_pow(long n, int acc)
{
	if (n == 0)
		return (acc);
	else if (n > 9 || n < -9)
		return (get_pow(n / 10, ++acc));
	else
		return (acc);
}

static void	set_nbr(char *s, long n, int sign)
{
	int	pow;

	if (n != 0)
		set_nbr(s, n / 10, sign);
	pow = get_pow(n, 1);
	if (pow == 0)
		s[0] = '0';
	if (pow > 0 && sign > 0)
		s[pow - 1] = "0123456789"[n % 10];
	else if (pow > 0 && sign < 0)
		s[pow - sign - 1] = "0123456789"[n % 10];
	if (pow == 1 && sign < 0)
		s[0] = '-';
}

static char	*ft_utoa(long n)
{	
	char	*nbr;
	int		nbr_len;
	int		sign;

	sign = 1;
	nbr_len = get_pow(n, 1);
	if (n < 0)
	{
		nbr_len++;
		sign = -1;
		n *= -1;
	}
	nbr = malloc(sizeof(*nbr) * (nbr_len + 1));
	if (nbr == NULL)
		return (NULL);
	set_nbr(nbr, n, sign);
	nbr[nbr_len] = '\0';
	return (nbr);
}

int	ft_printf_dec(int data)
{
	char	*str;
	int		length;

	str = ft_utoa(data);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}

int	ft_printf_unsigned_dec(unsigned int data)
{
	char			*str;
	int				length;

	str = ft_utoa(data);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}
