/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:10:49 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:43:40 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_robio **a, char *str)
{
	int		tmp;
	t_robio	*r;

	if (!a || !*a || !(*a)->next)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	r = (*a)->next;
	tmp = (*a)->content;
	(*a)->content = r->content;
	r->content = tmp;
	indexmystack(a);
}

void	ft_ss(t_robio **a, t_robio **b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ft_swap(a, NULL);
	ft_swap(b, NULL);
}

void	ft_rotate(t_robio **a, char *str)
{
	t_robio	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_lstlast(*a)->next = tmp;
	indexmystack(a);
}

void	rr(t_robio **a, t_robio **b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
}
