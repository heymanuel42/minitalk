/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:29:17 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/11 13:56:11 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "printf/ft_printf.h"
#include <signal.h>

int	pid_ok(const char *pid_str)
{
	while (*pid_str)
	{
		if (!ft_isdigit(*pid_str))
			return (-1);
		pid_str++;
	}
	return (0);
}

int	send_bit(int pid, int i)
{
	if (i)
		return (kill(pid, B_1));
	else
		return (kill(pid, B_0));
}

int	send_char(int pid, char c)
{
	int	b;

	b = 1;
	while (b < 128)
	{
		if (send_bit(pid, c & 1) < 0)
			return (-1);
		b <<= 1;
		c >>= 1;
		usleep(100);
	}
	return (0);
}

int	send_str(int pid, const char *str)
{
	while (*str)
	{
		if (send_char(pid, (unsigned int)*str) < 0)
			return (-1);
		str++;
	}
	return (send_char(pid, '\0'));
}
