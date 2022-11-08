/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:13:30 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 11:14:40 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(void *data)
{
	if (data == NULL)
	{
		ft_putstr_fd("0x0", 1);
		return (ft_strlen("0x0"));
	}
	ft_putstr_fd("0x", 1);
	return (2 + ft_printf_hex_low((unsigned long) data));
}
