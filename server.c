/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 18:26:01 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>

static int	g_nbits = 0;

void	handler(int sig)
{
	static int	ascii = 0;

	g_nbits++;
	if (g_nbits < 8)
	{
		if (sig == SIGUSR1)
			ascii += ft_pow(2, g_nbits - 1);
	}
	else if (g_nbits >= 8)
	{
		g_nbits = 0;
		ft_printf("%c", ascii);
		ascii = 0;
	}
}

int	main(void)
{
	ft_printf("My PID is: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}
