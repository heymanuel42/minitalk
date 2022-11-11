/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/11 14:11:27 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"

static void	handler(int sig, siginfo_t *info, void *d);

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

static void	print_and_free()
{
	ft_printf();
}
static void	handler(int sig, siginfo_t *info, void *d)
{
	static unsigned short	unicode;
	static int				nbits = 1;

	(void)d;
	if (info->si_pid > 0 && !info->si_errno)
	{
		if (sig == B_1)
			unicode |= nbits;
		nbits <<= 1;
		if (nbits == 0b1000000000000000)
		{
			g_message = ft_append(g_message, unicode);
			nbits = 1;
			if (unicode == 0)
			{
				ft_printf("%s\n", g_message);
				if (kill(info->si_pid, B_0) < 0)
					ft_printf("lost bit\n");
				return ;
			}
			unicode = 0;
		}
		if (kill(info->si_pid, B_1) < 0)
			ft_printf("lost bit\n");
	}
}
