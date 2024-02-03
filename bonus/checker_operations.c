/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:51 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/04 00:03:23 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_swap(t_robio **a)
{
	int		tmp;
	t_robio	*r;

	if (!a || !*a || !(*a)->next)
		return ;
	r = (*a)->next;
	tmp = (*a)->content;
	(*a)->content = r->content;
	r->content = tmp;
	indexmystack(a);
}

void	ft_ss(t_robio **a, t_robio **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_rotate(t_robio **a)
{
	t_robio	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_lstlast(*a)->next = tmp;
	indexmystack(a);
}

void	rr(t_robio **a, t_robio **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	indexmystack(t_robio **a)
{
	int		i;
	t_robio	*tmp;

	tmp = (*a);
	if (!a || !(*a) || !(*a)->next)
		return ;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}
