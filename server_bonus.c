/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/11 10:46:49 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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
		ft_printf("trouble setting up signal mask errno: %d\n", errno);
		return (-1);
	}
	action.sa_flags = SA_SIGINFO | SA_NODEFER;
	action.sa_sigaction = handler;
	if (sigaction(B_1, &action, NULL) < 0 || sigaction(B_0, &action, NULL) < 0)
	{
		ft_printf("signal not established errno: %d\n", errno);
		return (-1);
	}
	while (1)
		pause();
	return (0);
}

static void	handler(int sig, siginfo_t *info, void *d)
{
	static unsigned int	fchar;
	static int			nbits = 1;

	(void)d;
	if (sig == B_1)
		fchar |= nbits;
	nbits <<= 1;
	if (kill(info->si_pid, B_1) < 0)
		ft_printf("lost bit errno: %d\n", errno);
	if (nbits == 128)
	{
		g_message = ft_append(g_message, fchar);
		if (fchar == 0)
		{
			if (kill(info->si_pid, B_0) < 0)
				ft_printf("lost bit errno: %d\n", errno);
			ft_printf("%s\n", g_message);
			free(g_message);
			g_message = NULL;
		}
		nbits = 1;
		fchar = 0;
	}
}
