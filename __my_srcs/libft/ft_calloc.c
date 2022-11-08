/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:11:26 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/25 18:36:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nemb, size_t size)
{
	void	*data;

	data = malloc(size * nemb);
	if (!data)
		return (NULL);
	ft_bzero(data, size * nemb);
	return (data);
}
