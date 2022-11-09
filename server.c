/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 22:14:59 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	handler(int sig, siginfo_t *info, void *d)
{
	static char	ascii = 0;
	static int	nbits = 0;

	(void)d;
	nbits++;
	if (sig == B_1)
		ascii += ft_pow(2, nbits - 1);
	if (nbits == 8)
	{
		ft_putchar_fd(ascii, 1);
		if (ascii == 0)
		{
			ft_printf("\n");
			send_bit(info->si_pid, B_1);
		}
		nbits = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("My PID is: %d\n", getpid());
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	sigaction(B_1, &action, NULL);
	sigaction(B_0, &action, NULL);
	while (1)
		pause();
	return (0);
}
