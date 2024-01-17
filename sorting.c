/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:44:26 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/16 19:44:23 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_robio **a)
{
	int	max_idx;

	max_idx = 0;
	check_max(a, &max_idx);
	if (max_idx == 0)// ghir lmax
		ft_rotate(a);
	if (max_idx == 1)
		ft_reverse_rotate(a);
	if ((*a)->content > (*a)->next->content)
		ft_swap(a);

}

void	sorting_five(t_robio **a, t_robio **b)
{
	int min =  check_min(a);
	if (ft_lstsize(*a) > 3)
	{
		if (min > ft_lstsize(*a) / 2)
			while (min++ < ft_lstsize(*a))
				ft_reverse_rotate(a);
		else
			while (min--)
				ft_rotate(a);
		push_b(a, b);
		sorting_five(a, b);
	}
	sorting_three(a);
	push_a(b, a);
	push_a(b, a);
}


/*
	if (mahed size > 3)
	{
		if min > size / 2
			while min < size diyal stack
				rra();
		else
			while (min--)
				ra();
		push_B();
		sorting_five();
	}
	sorting_three()
	push_A();
	push_A();
*/
