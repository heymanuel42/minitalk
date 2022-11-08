/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 14:31:46 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("1");
	}
	else
	{
		ft_printf("0");
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("My PID is: %d\n", getpid());
	action.sa_flags = 0;
	action.sa_handler = handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while (1)
	{
		pause();
	}
	return (0);
}
