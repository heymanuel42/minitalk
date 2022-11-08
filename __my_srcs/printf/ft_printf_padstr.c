/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:41:11 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 23:29:09 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill(void *data, char c, int n, int start)
{
	int	i;

	i = start;
	while (i < n + start)
	{
		((unsigned char *)data)[i] = c;
		i++;
	}
}

int	ft_printf_padstr(void *data, int n, char c, t_padding padding)
{
	char	*new;
	int		len;

	len = ft_strlen(data) + n;
	new = malloc(len + 1);
	if (padding == LEFT)
	{
		fill(new, c, n - ft_strlen(data), 0);
		ft_strlcat(new, data, len + 1);
	}
	else
	{
		ft_memcpy(new, data, ft_strlen(data));
		fill(new, ' ', n - ft_strlen(data), ft_strlen(data));
	}
	free(data);
	ft_printf_str(new);
	return (len);
}
