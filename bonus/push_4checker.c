/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_4checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:01:09 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/04 00:01:44 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_b(t_robio **a, t_robio **b)
{
	t_robio	*tmp;

	if (!*a)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	indexmystack(a);
	indexmystack(b);
}

void	push_a(t_robio **b, t_robio **a)
{
	t_robio	*tmp;

	if (!*b)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	indexmystack(a);
	indexmystack(b);
}
