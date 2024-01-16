/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:52:03 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/16 02:35:21 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction qui loupe ela stack kaml bash kan indexi stack

void		indexmystack(t_robio **a)
{
	int i;
	t_robio *tmp = (*a);//pointeur vers le premier element

	if (!a || !(*a) || !(*a)->next)
		return ;
	i = 0;
	while (tmp)
	{
		tmp->index = i; //index de chaque noeud
		i++;
		tmp = tmp->next;
	}
}

void		check_max(t_robio **a, int *max_idx)
{
	int	max;
	t_robio *tmp = *a;

	max = tmp->content;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content > max)
		{
				*max_idx = tmp->index;
				max = tmp->content;
		}
	}
}

int	check_min(t_robio **a)
{
	int	min;
	int min_idx;

	t_robio *tmp = *a;
	min = tmp->content;
	min_idx = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content < min)
		{
			min_idx = tmp->index;
			min = tmp->content;
		}
	}
	return (min_idx);
}