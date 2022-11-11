/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/11 13:49:38 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	handler(int sig, siginfo_t *info, void *d);
static int	test_params(int argc, char*argv[]);
static int	set_actions(void);

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

static void	handler(int sig, siginfo_t *info, void *d)
{
	(void)sig;
	(void)d;
	if (sig == B_0)
		ft_printf("message sent successfully to process: %d\n", info->si_pid);
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
		ft_printf("trouble setting up signal\n");
		return (-1);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	if (sigaction(B_0, &action, NULL) < 0 || sigaction(B_1, &action, NULL) < 0)
	{
		ft_printf("signal not established\n");
		return (-1);
	}
	return (0);
}
