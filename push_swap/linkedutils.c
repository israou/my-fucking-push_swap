/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:37:15 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/02 19:03:48 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_robio	*ft_lstnew(int content)
{
	t_robio	*node;

	node = malloc(sizeof(t_robio));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->move = 0;
	node->index = 0;
	return (node);
}

t_robio	*ft_lstlast(t_robio *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_robio **lst, t_robio *new)
{
	t_robio	*lis;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		lis = ft_lstlast(*lst);
		lis->next = new;
	}
	else
	{
		(*lst) = new;
	}
	indexmystack (lst);
}

void	ft_lstadd_front(t_robio **lst, t_robio *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_robio *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
