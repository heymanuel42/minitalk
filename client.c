/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/11 12:41:50 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	test_params(int argc, char*argv[]);

int	main(int argc, char *argv[])
{
	int	pid;

	if (test_params(argc, argv) < 0)
		return (1);
	pid = ft_atoi(argv[1]);
	if (send_str(pid, argv[2]) < 0)
		ft_printf("Could not deliver message\n");
	return (0);
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
