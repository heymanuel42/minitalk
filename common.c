/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:29:17 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 21:14:29 by ejanssen         ###   ########.fr       */
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
			return (0);
		pid_str++;
	}
	return (1);
}

int	send_bit(int pid, int i)
{
	if (i)
		return (kill(pid, SIGUSR1));
	else
		return (kill(pid, SIGUSR2));
}

int	send_char(int pid, char c)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if (send_bit(pid, c & 1) < 0)
			return (0);
		b++;
		c >>= 1;
		usleep(100);
	}
	return (1);
}

int	send_str(int pid, const char *str)
{
	while (*str)
	{
		if (!(send_char(pid, *str)))
			return (0);
		str++;
	}
	return (send_char(pid, '\0'));
}
