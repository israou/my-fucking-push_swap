/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:41:30 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:41:39 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_robio **a, t_robio **b, char *str)
{
	t_robio	*tmp;

	if (!*a)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	indexmystack(a);
	indexmystack(b);
}

void	push_a(t_robio **b, t_robio **a, char *str)
{
	t_robio	*tmp;

	if (!*b)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	indexmystack(a);
	indexmystack(b);
}
