/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:06:11 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/30 22:19:59 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_up(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best)
{
	while (top_a->content != (*a)->content && best->content != (*b)->content)
		rr(a, b, "rr\n");
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
