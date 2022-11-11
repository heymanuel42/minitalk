/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:27:32 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/11 12:44:15 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_BONUS_H
# define COMMON_BONUS_H
# include <signal.h>
# include "printf/ft_printf.h"

# define B_0 SIGUSR2
# define B_1 SIGUSR1

int	send_bit(int pid, int i);
int	send_char(int pid, unsigned short c);
int	send_str(int pid, const char *str);
int	pid_ok(const char *pid_str);

#endif