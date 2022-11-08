/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:32:12 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/26 19:35:21 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	size;
	unsigned int	i;

	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
}
