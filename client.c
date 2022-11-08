/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 14:31:23 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>

int	main(int argc, char *argv[])
{
	char				c;
	int					b;
	int					pid;

	(void) argc;
	pid = ft_atoi(argv[1]);
	ft_printf("%d\n", pid);
	c = 'H';
	b = 8;
	while (b)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		b--;
		usleep(10);
	}
	ft_printf("\n");
	ft_printf("Hello world\n");
	return (0);
}
