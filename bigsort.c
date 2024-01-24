/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:20:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/23 20:45:32 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_robio	*get_top(t_robio *a, t_robio *b) //top f a
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
		if (first->content < b->content && b->content < second->content)
			return (second);
		a = a->next;
	}
	return (NULL);
}

t_robio		*get_best_element(t_robio *b)//kat returner ghir raqm li ando min move f b
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

void	step_by_step(t_robio **a, t_robio **b, int size)
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
	// step_four
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
