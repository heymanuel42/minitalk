/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:09:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 17:33:33 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_start(char const *s1, char const *set)
{
	int	current;

	current = 0;
	if (ft_strlen(s1) == 0)
		return (current);
	while (ft_strchr(set, s1[current]))
		current++;
	return (current);
}

static int	trim_end(char const *s1, char const *set)
{
	int	current;

	current = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
		return (current);
	while (ft_strchr(set, s1[current]))
		current--;
	return (current);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	start = trim_start(s1, set);
	end = trim_end(s1, set) - start;
	res = ft_substr(s1, start, end + 1);
	if (res == NULL)
		return (NULL);
	return (res);
}
