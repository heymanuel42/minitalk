/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:11:39 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/25 18:00:04 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	src_len;

	src_len = ft_strlen(src) + 1;
	cpy = malloc(src_len * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, src, src_len);
	return (cpy);
}
