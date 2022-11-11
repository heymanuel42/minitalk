/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/11 14:06:24 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	handler(int sig, siginfo_t *info, void *ctx);

char	*g_message = NULL;

int	main(void)
{
	struct sigaction	action;

	ft_printf("My PID is: %d\n", getpid());
	if (sigemptyset(&action.sa_mask) < 0
		|| sigaddset(&action.sa_mask, B_0) < 0
		|| sigaddset(&action.sa_mask, B_1) < 0)
	{
		ft_printf("trouble setting up signal mask\n");
		return (-1);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	if (sigaction(B_1, &action, NULL) < 0 || sigaction(B_0, &action, NULL) < 0)
	{
		ft_printf("signal not established\n");
		return (-1);
	}
	while (1)
		pause();
	return (0);
}

static void	handler(int sig, siginfo_t *info, void *ctx)
{
	static char	ascii;
	static int	nbits = 1;

	(void)ctx;
	(void)info;
	if (info->si_pid > 0)
	{
		if (sig == B_1)
			ascii |= nbits;
		nbits <<= 1;
		if (nbits == 128)
		{
			g_message = ft_append(g_message, ascii);
			if (ascii == 0)
			{
				ft_printf("%s\n", g_message);
				if (g_message)
					free(g_message);
				g_message = NULL;
			}
			nbits = 1;
			ascii = 0;
		}
	}
}
