/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:20:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/18 01:50:58 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_move(t_robio *b, t_robio *top, int size_a, int size_b)
{
	int two_up,two_down, up_down, down_up;


	two_up = ft_max(top->index, b->index);

	two_down = ft_max(size_a - top->index, size_b - b->index);

	up_down = top->index + size_b - b->index;

	down_up = size_a - top->index + b->index;

	if (two_up <= two_down && two_up <= up_down && two_up <= down_up)
		return  (two_up);
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
		return  (1);
	if (two_down <= two_up && two_down <= up_down && two_down <= down_up)
		return (2);
	if (up_down <= two_up && up_down <= two_down && up_down <= down_up)
		return (3);
	if (down_up <= two_up && down_up <= two_down && down_up <= up_down)
		return (4);
	return (0);
}

t_robio	*get_top(t_robio *a, t_robio *b)
{
	t_robio	*max_a = max_element(&a);
	t_robio	*min_a = min_element(&a);

	if (b->content > max_a->content || b->content < min_a->content)
		return (min_a);
	if (a->content > b->content && ft_lstlast(a)->content < b->content)
		return (a);
	while (a && a->next)
	{
		t_robio *first = a;
		t_robio *second = a->next;
		if (first->content < b->content && b->content  < second->content)
			return (second);
		a = a->next;
	}
	return (NULL);
}

void	index_moves(t_robio *a, t_robio **b)
{
	t_robio *stack_b = *b;
	t_robio *top;
	while (stack_b)
	{
		top = get_top(a, stack_b);
		stack_b->move = get_min_move(stack_b, top, ft_lstsize(a), ft_lstsize(*b)) + 1;
		stack_b = stack_b->next;
	}

}

t_robio		*get_best_element(t_robio *b)
{
	int	min_move;
	t_robio *tmp = b;

	if (!tmp)
		return (NULL);
	min_move = tmp->move;
	while (tmp)
	{
		if (tmp->move < min_move)
		{
			min_move = tmp->move;
		}
		tmp = tmp->next;
	}
	tmp = b;
	while (tmp)
	{
		if (min_move == (tmp)->move)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	two_up(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best)
{

	while (top_a->content != (*a)->content && best->content != (*b)->content)
		rarb(a, b, "rr\n"); // hit msifta ghir * w rarb kiyakhd ** ayi haja katbedel
	while (top_a->content != (*a)->content)
		ft_rotate(a, "ra\n");
	while (best->content != (*b)->content)
		ft_rotate(b, "rb\n");
}

void	two_down(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best)
{
	while (top_a->content != (*a)->content && best->content != (*b)->content)
		ft_rrr(a, b, "rrr\n");//hit msifta ghir * w rarb kiyakhd ** ayi haja katbedel
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

void push_best_move_to_a(t_robio **a, t_robio **b, t_robio *best)
{
	t_robio *top = get_top(*a, best);
	if (type_of_move(best, top, *a, *b) == 1)
		two_up(a, b, top, best);
	else if (type_of_move(best, top, *a, *b) == 2)
		two_down(a, b, top, best);
	else if (type_of_move(best, top, *a, *b) == 3)
		up_down(a, b, top, best);
	else if (type_of_move(best, top, *a, *b) == 4)
		down_up(a, b, top, best);
	push_a(b, a, "pa\n");
}
void	step_one(t_robio **a, t_robio **b, int size)
{
	int	i;

	i = 0;
	// step_one
	while (i <= size - 3)//bach nkheli 2 f a w kolshy ymshi l b
	{
		push_b(a, b, "pb\n");
		i++;
	}
	// step_two
	int size_b = ft_lstsize(*b);
	while (size_b--)
	{
		index_moves(*a, b);
		// step three
		push_best_move_to_a(a, b, get_best_element(*b));
	}
	// step four
	if (min_element(a)->index < ft_lstsize(*a) / 2)
	{
		int i = min_element(a)->index;
		while (i--)
			ft_rotate(a, "ra\n");
	}
	else
	{
		int i = min_element(a)->index;
		while (i++ < ft_lstsize(*a))
			ft_reverse_rotate(a, "rra\n");
	}
}
