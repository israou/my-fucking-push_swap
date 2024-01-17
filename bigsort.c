/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:20:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/17 22:03:17 by ichaabi          ###   ########.fr       */
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

// t_robio		move_the_min(t_robio **a, t_robio **b)
// {
// 	t_robio *top = top->index;
// 	t_robio *stack_b = *b;
// 	int	size_a = ft_lstsize(a);
// 	int	size_b = ft_lstsize(b);

// 	t_robio *to_move = get_min_move(a, top, size_a, size_b);
// 	while (stack_b->index == to_move)
// 	{
// 		push_a(b, a);
// 		stack_b = stack_b->next;
// 	}
// 	//khasni nmover li endo min de move f b to a
// }
void	step_one(t_robio **a, t_robio **b, int size)
{
	int	i;

	i = 0;
	puts("here");
	// step_one
	while (i <= size - 3)//bach nkheli 2 f a w kolshy ymshi l b
	{
		push_b(a, b);
		i++;
	}

	// step_two

	int size_b = ft_lstsize(*b);
	while (size_b--)
	{
		index_moves(*a, b);
		// step three
		/* move the minimum move of the elem of b to a */
	}
}

// void	two_up(t_robio **a, t_robio **b)
// {

// }