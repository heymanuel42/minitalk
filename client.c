/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/10 19:37:11 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	handler(int sig, siginfo_t *info, void *d)
{
	static int	nbits;

	(void)sig;
	(void)d;
	nbits++;
	if (sig == B_0)
	{
		ft_printf("%d bits sent to %d\n", nbits - 1, info->si_pid);
		nbits = 0;
	}
}

static int	test_params(int argc, char*argv[])
{
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments; expected 2 arguments\n");
		return (-1);
	}
	if (pid_ok(argv[1]) < 0)
	{
		ft_printf("pid is not valid\n");
		return (-1);
	}
	return (0);
}

static int	set_actions(void)
{
	struct sigaction	action;

	if (sigemptyset(&action.sa_mask) < 0
		|| sigaddset(&action.sa_mask, B_0) < 0
		|| sigaddset(&action.sa_mask, B_1) < 0)
	{
		ft_printf("trouble setting up signal errno: %d\n", errno);
		return (-1);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	if (sigaction(B_0, &action, NULL) < 0 || sigaction(B_1, &action, NULL) < 0)
	{
		ft_printf("signal not established quitting\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int					pid;

	if (test_params(argc, argv) < 0)
		return (1);
	pid = ft_atoi(argv[1]);
	if (set_actions() < 0)
		return (1);
	if (send_str(pid, argv[2]) < 0)
		ft_printf("Could not deliver message\n");
	return (0);
}
