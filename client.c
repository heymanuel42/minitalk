/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 13:29:28 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	handler(int sig)
{
	(void)sig;
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	action;

	action.sa_flags = 0;
	action.sa_handler = handler;
	sigaction(SIGUSR1, &action, NULL);
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
	if (!send_str(pid, argv[2]))
		ft_printf("Your message could not be delivered");
	return (0);
}
