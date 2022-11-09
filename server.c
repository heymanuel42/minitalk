/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 13:32:22 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

struct sigaction	g_action;

void	test(int sig, siginfo_t *info, void *d)
{
	static char	ascii = 0;
	static int	nbits = 0;

	(void)d;
	nbits++;
	if (sig == SIGUSR1)
		ascii += ft_pow(2, nbits - 1);
	kill(info->si_pid, SIGUSR2);
	if (nbits == 8)
	{
		ft_putchar_fd(ascii, 1);
		nbits = 0;
		ascii = 0;
	}
}

int	main(void)
{
	ft_printf("My PID is: %d\n", getpid());
	g_action.sa_flags = 0;
	g_action.sa_sigaction = test;
	sigaction(SIGUSR1, &g_action, NULL);
	sigaction(SIGUSR2, &g_action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
