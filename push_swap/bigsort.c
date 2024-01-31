/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:20:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/31 18:44:13 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_robio	*get_top(t_robio *a, t_robio *b)
{
	t_robio	*max_a;
	t_robio	*min_a;
	t_robio	*first;
	t_robio	*second;

	max_a = max_element(&a);
	min_a = min_element(&a);
	if (b->content > max_a->content || b->content < min_a->content)
		return (min_a);
	if (a->content > b->content && ft_lstlast(a)->content < b->content)
		return (a);
	while (a && a->next)
	{
		first = a;
		second = a->next;
		if (first->content < b->content && b->content < second->content)
			return (second);
		a = a->next;
	}
	return (NULL);
}

t_robio	*get_best_element(t_robio *b)
{
	int		min_move;
	t_robio	*tmp;

	tmp = b;
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

void	push_best_move_to_a(t_robio **a, t_robio **b, t_robio *best)
{
	t_robio	*top;

	top = get_top(*a, best);
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

void	index_moves(t_robio *a, t_robio **b)//kan zid nejma b & kan hayedha b *
{
	t_robio	*stack_b;
	t_robio	*top;
	//t_robio	*stack_k = (*b);

	stack_b = *b;
	while (stack_b)
	{
		top = get_top(a, stack_b);
		stack_b->move = get_min_move(stack_b, top, ft_lstsize(a), ft_lstsize(*b)) + 1;
		//printf("stack_k == %d\n", stack_k->content);
		//printf("stack_k move == %d\n", stack_k->move);
		stack_b = stack_b->next;
	}
	//aff(a, *b, 10);
}

void	step_by_step(t_robio **a, t_robio **b, int size)
{
	int	i;
	int	size_b;

	i = -1;
	while (++i < size - 2)
		push_b(a, b, "pb\n");
	size_b = ft_lstsize(*b);
	while (size_b--)
	{
		index_moves(*a, b);
		push_best_move_to_a(a, b, get_best_element(*b));
	}
	if (min_element(a)->index < ft_lstsize(*a) / 2)
	{
		i = min_element(a)->index;
		while (i--) //postdesincrementation,, ki qaren 5 != 0 true, kinqes men 5 qbel may rotati
			ft_rotate(a, "ra\n");
	}
	else
	{
		i = min_element(a)->index;
		while (i++ < ft_lstsize(*a))
			ft_reverse_rotate(a, "rra\n");
	}
}
