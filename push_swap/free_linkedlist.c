/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linkedlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:03:16 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:48:53 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_robio **lst)
{
	t_robio	*node;

	if (!lst)
		return ;
	node = (*lst);
	while (*lst)
	{
		node = (*lst)->next;
		free(*lst);
		*lst = node;
	}
	lst = NULL;
}
