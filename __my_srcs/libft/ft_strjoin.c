/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:05:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/26 18:55:39 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len == 0 && s2_len == 0)
		return (ft_strdup(""));
	new = malloc(s1_len + s2_len + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, s1_len + 1);
	ft_memcpy(new + s1_len, s2, s2_len + 1);
	new[s1_len + s2_len] = '\0';
	return (new);
}
