/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:27:32 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 21:09:04 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <signal.h>
# include "printf/ft_printf.h"

# define B_0 SIGUSR2
# define B_1 SIGUSR1

int	send_bit(int pid, int i);
int	send_char(int pid, char c);
int	send_str(int pid, const char *str);
int	pid_ok(const char *pid_str);

#endif