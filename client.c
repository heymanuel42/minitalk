/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 17:34:03 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>

static void	send_char(int pid, char c)
{
	int	b;

	b = 8;
	while (b)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		b--;
		c = c >> 1;
		usleep(10);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;

	(void) argc;
	pid = ft_atoi(argv[1]);
	send_char(pid, 'C');
	return (0);
}
