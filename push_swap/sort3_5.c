/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:44:26 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:28:57 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_robio **a)
{
	int	max_idx;

	max_idx = 0;
	check_max(a, &max_idx);
	if (max_idx == 0)
		ft_rotate(a, "ra\n");
	if (max_idx == 1)
		ft_reverse_rotate(a, "rra\n");
	if ((*a)->content > (*a)->next->content)
		ft_swap(a, "sa\n");
}

void	sorting_five(t_robio **a, t_robio **b)
{
	int	min;

	min = check_min(a);
	if (ft_lstsize(*a) > 3)
	{
		if (min > ft_lstsize(*a) / 2)
			while (min++ < ft_lstsize(*a))
				ft_reverse_rotate(a, "rra\n");
		else
			while (min--)
				ft_rotate(a, "ra\n");
		push_b(a, b, "pb\n");
		sorting_five(a, b);
	}
	sorting_three(a);
	push_a(b, a, "pa\n");
	push_a(b, a, "pa\n");
}
