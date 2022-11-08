/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:44 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/07 19:39:21 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*get_next_word(const char *str, char sep, char **new)
{
	int	i;
	int	word;
	int	start;

	word = 0;
	i = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			start = i;
			while (str[i] != sep && str[i] != '\0')
			{
				word++;
				i++;
			}
			*new = ft_substr(str, start, word);
			return ((char *)str + i);
		}
		i++;
	}
	*new = ft_substr(str, i, word);
	return ((char *)str + i);
}

static int	count_words(const char *str, char sep)
{
	int		i;
	int		nwords;

	i = 0;
	nwords = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i] != '\0')
		{
			while (str[i] != sep && str[i] != '\0')
			{
				i++;
			}
			++nwords;
			if (str[i] == '\0')
				return (nwords);
		}
		i++;
	}
	return (nwords);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*sub;
	int		nwords;
	int		i;

	sub = NULL;
	nwords = count_words(s, c);
	array = (char **)malloc((nwords + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (nwords == 0)
	{
		array[0] = NULL;
		return (array);
	}
	i = 0;
	while (nwords > 0)
	{
		s = get_next_word(s, c, &sub);
		array[i] = sub;
		i++;
		nwords--;
	}
	array[i] = NULL;
	return (array);
}
