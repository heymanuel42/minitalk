/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:07:55 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/25 13:10:58 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*start;

	start = src;
	if (dstsize > 0)
	{
		while (dstsize - 1 > 0 && *src)
		{
			*dst++ = *src++;
			dstsize--;
		}
	}
	while (*src++)
		;
	if (dstsize > 0)
		*dst = '\0';
	return (src - start - 1);
}
