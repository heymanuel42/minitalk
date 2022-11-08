/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:03:40 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 11:14:37 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*append(char *str, char c)
{
	char	*new;
	size_t	old_l;

	if (str == NULL)
	{
		new = malloc(2);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	old_l = ft_strlen(str);
	new = malloc(sizeof(*new) * old_l + 2);
	new = ft_memcpy(new, str, old_l);
	new[old_l] = c;
	new[old_l + 1] = '\0';
	free(str);
	return (new);
}

static void	set_nbr(char **s, unsigned long n, const char *set)
{
	if (n >= 16)
		set_nbr(s, n / 16, set);
	*s = append(*s, set[n % 16]);
}

static char	*ft_utoa(unsigned long n, const char *set)
{	
	char	*nbr;

	nbr = NULL;
	set_nbr(&nbr, n, set);
	return (nbr);
}

int	ft_printf_hex_low(unsigned long data)
{
	char	*str;
	int		length;

	str = ft_utoa(data, "0123456789abcdef");
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}

int	ft_printf_hex_up(unsigned long data)
{
	char	*str;
	int		length;

	str = ft_utoa(data, "0123456789ABCDEF");
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}
