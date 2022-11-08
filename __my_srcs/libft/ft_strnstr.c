/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:12:18 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/25 17:53:58 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	sub_str_len;
	int		i;

	i = 0;
	sub_str_len = ft_strlen(needle);
	if (len == 0 && sub_str_len > 0)
		return (NULL);
	if (sub_str_len <= 0)
		return ((char *) haystack);
	while (haystack[i] != '\0' && i + sub_str_len <= len)
	{
		if (!ft_strncmp(haystack + i, needle, sub_str_len))
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
