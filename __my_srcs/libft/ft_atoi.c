/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:14:02 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 17:49:48 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_white_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t'
		|| str[i] == '\n'
		|| str[i] == '\v'
		|| str[i] == '\f'
		|| str[i] == '\r'
		|| str[i] == ' ')
			i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	idx;
	int	pow;
	int	res;
	int	i;

	i = 0;
	res = 0;
	pow = 0;
	sign = 1;
	idx = get_white_spaces(str);
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx + pow] && ft_isdigit(str[idx + pow]))
		pow++;
	while (i < pow && ft_isdigit(str[idx + i]))
	{
		res += (str[idx + i] - '0') * ft_pow(10, pow - i - 1);
		i++;
	}
	return (sign * res);
}
