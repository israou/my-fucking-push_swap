/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_4checkerlinkedlist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:02:37 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:55:49 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_linkedclear(t_robio **lst)
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
