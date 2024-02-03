/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:43:09 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:43:55 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_robio **a, char *str)
{
	t_robio	*tmp;
	t_robio	*tmp1;

	if (!a || !*a || !(*a)->next)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = ft_lstlast(*a);
	tmp1 = *a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	ft_lstadd_front(a, tmp);
	indexmystack(a);
}

void	ft_rrr(t_robio **a, t_robio **b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ft_reverse_rotate(a, NULL);
	ft_reverse_rotate(b, NULL);
}
