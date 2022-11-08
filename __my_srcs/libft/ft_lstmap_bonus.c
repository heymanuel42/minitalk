/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:56:41 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/31 11:47:39 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static t_list	*new_add_back(t_list **lst, void *content, void (*del)(void*))
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		ft_lstclear(lst, del);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	ft_lstadd_back(lst, node);
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*new;

	new = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_add_back(&new, f(lst->content), del);
		lst = lst->next;
	}
	return (new);
}
