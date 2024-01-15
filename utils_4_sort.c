/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:52:03 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/15 18:37:18 by ichaabi          ###   ########.fr       */
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

//fonction qui check le plus grand nombre de linkedlist

void		check_max_min(t_robio **a, int *min_idx, int *max_idx)
{
	int	min;
	int	max;
	min = (*a)->content;
	max = (*a)->content;

	while ((*a)->next)
	{
		(*a) = (*a)->next;//pour avancer dans la liste
		if ((*a)->content < min)//comparer la valeur du noeud actuel avc la valeur min actuelle
		{
			*min_idx = (*a)->index;
			min = (*a)->content;
		}
		if ((*a)->content > max)
		{
				*max_idx = (*a)->index;
				max = (*a)->content;
		}
	}
}