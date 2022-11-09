/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 22:12:01 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	handler(int sig, siginfo_t *info, void *d)
{
	(void)d;
	if (sig == B_1)
	{
		ft_printf("From %d; Message was sent successfully\n", info->si_pid);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	action;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments; expected 2 arguments\n");
		return (1);
	}
	if (!pid_ok(argv[1]))
	{
		ft_printf("pid is not valid\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	action.sa_sigaction = handler;
	sigaction(SIGUSR1, &action, NULL);
	if (!send_str(pid, argv[2]))
		ft_printf("Your message could not be delivered");
	return (0);
}
