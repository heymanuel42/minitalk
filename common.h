/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:27:32 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/09 12:31:40 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <signal.h>
# include "printf/ft_printf.h"

int	send_bit(int pid, int i);
int	send_char(int pid, char c);
int	send_str(int pid, const char *str);
int	pid_ok(const char *pid_str);

#endif