/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:52:14 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/25 19:00:19 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	id;

	id = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (id < n)
	{
		((char *)dst)[id] = ((char *)src)[id];
		id++;
	}
	return (dst);
}
