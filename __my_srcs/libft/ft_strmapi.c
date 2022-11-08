/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:24:05 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/26 19:30:59 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*mapped;

	size = ft_strlen(s);
	mapped = malloc(size * sizeof(*mapped) + 1);
	if (mapped == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
