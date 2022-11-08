/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:00:57 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/25 19:17:59 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = dst;
	src_tmp = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			dst_tmp[len] = src_tmp[len];
		}
	}
	return (dst);
}
