/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:10:49 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/13 23:20:01 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_robio **a)//void hit deja kan sifto **a donc ki t updata f stack
{
	int	tmp;
	t_robio	*b;

	if (!a || !*a || !(*a)->next)
		return ;
	b = (*a)->next;
	tmp = (*a)->content;
	(*a)->content = b->content;
	b->content = tmp;
}

void	ft_ss(t_robio **a, t_robio **b)
{
	if (!a && !b)
		return ;
	ft_swap(a);
	ft_swap(b);
}

void	ft_rotate(t_robio **a)
{
	t_robio	*tmp;
	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	(*a) = (*a)->next;//update pour a
	tmp->next = NULL;
	ft_lstlast(*a)->next = tmp;

}

void	ft_reverse_rotate(t_robio **a)
{
	t_robio	*tmp;
	if (!a || !*a || !(*a)->next)
		return ;
	tmp = ft_lstlast(*a);
	tmp->next = (*a);
	(*a) = (*a)->next;
}

void	ft_rr(t_robio **a, t_robio **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}