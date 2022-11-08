/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:11:26 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/25 18:51:16 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	id;

	id = 0;
	while (id < n)
	{
		((char *)s)[id] = c;
		id++;
	}
	return (s);
}
