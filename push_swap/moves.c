/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:06:11 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/26 23:41:01 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_up(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best)
{
	while (top_a->content != (*a)->content && best->content != (*b)->content)
		rarb(a, b, "rarb\n");
	while (top_a->content != (*a)->content)
		ft_rotate(a, "ra\n");
	while (best->content != (*b)->content)
		ft_rotate(b, "rb\n");
}

void	two_down(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best)
{
	while (top_a->content != (*a)->content && best->content != (*b)->content)
		ft_rrr(a, b, "rrr\n");
	while (top_a->content != (*a)->content)
		ft_reverse_rotate(a, "rra\n");
	while (best->content != (*b)->content)
		ft_reverse_rotate(b, "rrb\n");
}

void	up_down(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best)
{
	while (top_a->content != (*a)->content)
		ft_rotate(a, "ra\n");
	while (best->content != (*b)->content)
		ft_reverse_rotate(b, "rrb\n");
}

void	down_up(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best)
{
	while (top_a->content != (*a)->content)
		ft_reverse_rotate(a, "rra\n");
	while (best->content != (*b)->content)
		ft_rotate(b, "rb\n");
}

int	get_min_move(t_robio *b, t_robio *top, int size_a, int size_b)
{
	int two_up,two_down, up_down, down_up;


	two_up = ft_max(top->index, b->index);

	two_down = ft_max(size_a - top->index, size_b - b->index);

	up_down = top->index + size_b - b->index;

	down_up = size_a - top->index + b->index;
	if (two_up <= two_down && two_up <= up_down && two_up <= down_up)
		return (two_up);
	if (two_down <= two_up && two_down <= up_down && two_down <= down_up)
		return (two_down);
	if (up_down <= two_up && up_down <= two_down && up_down <= down_up)
		return (up_down);
	if (down_up <= two_up && down_up <= two_down && down_up <= up_down)
		return (down_up);
	return (0);
}

int	type_of_move(t_robio *elm_b, t_robio *elm_a, t_robio *a, t_robio *b)
{
	int two_up,two_down, up_down, down_up;


	two_up = ft_max(elm_a->index, elm_b->index);

	two_down = ft_max(ft_lstsize(a) - elm_a->index, ft_lstsize(b) - elm_b->index);

	up_down = elm_a->index + ft_lstsize(b) - elm_b->index;

	down_up = ft_lstsize(a) - elm_a->index + elm_b->index;

	if (two_up <= two_down && two_up <= up_down && two_up <= down_up)
		return (1);
	if (two_down <= two_up && two_down <= up_down && two_down <= down_up)
		return (2);
	if (up_down <= two_up && up_down <= two_down && up_down <= down_up)
		return (3);
	if (down_up <= two_up && down_up <= two_down && down_up <= up_down)
		return (4);
	return (0);
}