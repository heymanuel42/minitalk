/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:29:17 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 13:26:46 by ejanssen         ###   ########.fr       */
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
	static int	nbits;
	
	nbits++;
	if (i & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	return (1);
}

int	send_char(int pid, char c)
{
	int	b;
	int	status;

	b = 0;
	status = 0;
	while (b < 8)
	{
		if (c & 1)
			status = kill(pid, SIGUSR1);
		else
			status = kill(pid, SIGUSR2);
		b++;
		c = c >> 1;
		if (status != 0)
			return (0);
		pause();
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
	send_char(pid, '\0');
	return (1);
}
