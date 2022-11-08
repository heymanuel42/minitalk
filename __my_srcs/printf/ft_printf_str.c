/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:19:24 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 22:45:27 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(void *data)
{
	char	*str;
	int		length;

	if (data == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(data);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}
