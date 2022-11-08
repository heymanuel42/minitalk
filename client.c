/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 18:37:25 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>

// static int	pid_ok(const char *pid_str)
// {
// 	while (*pid_str)
// 	{
// 		if (!ft_isdigit(*pid_str))
// 			return (0);
// 		pid_str++;
// 	}
// 	return (1);
// }

static int	send_char(int pid, unsigned char c)
{
	int	b;
	int	status;

	(void)pid;
	b = 0;
	status = 0;
	ft_printf("\n%c %d\n", 61, (unsigned char)c);
	while (b < 8 * 4)
	{
		// if (c & 1)
		// 	status = kill(pid, SIGUSR1);
		// else
		// 	status = kill(pid, SIGUSR2);
		b++;
		c = c >> 1;
		usleep(5);
		if (status != 0)
			return (0);
	}
	return (1);
}

static int	send_str(int pid, const char *str)
{
	while (*str)
	{
		if (!(send_char(pid, (unsigned char)*str)))
			return (0);
		str++;
	}
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	int					pid;

// 	if (argc != 3)
// 	{
// 		ft_printf("Wrong number of arguments; expected 2 arguments\n");
// 		return (1);
// 	}
// 	if (!pid_ok(argv[1]))
// 	{
// 		ft_printf("pid is not valid\n");
// 		return (1);
// 	}
// 	pid = ft_atoi(argv[1]);
// 	if (!send_str(pid, argv[2]))
// 		ft_printf("Your message could not be delivered");
// 	return (0);
// }

//testing unicode
int	main(void)
{
	send_str(0, "à");
	return (0);
}
