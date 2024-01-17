/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:52:03 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/17 18:50:01 by ichaabi          ###   ########.fr       */
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

void		check_max(t_robio **a, int *max_idx)//kat qeleb lia ela lmax w kat etini index dialo
{
	int	max;
	t_robio *tmp = (*a);

	if (!tmp)
		return ;
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

t_robio		*max_element(t_robio **a)
{
	int	max;
	t_robio *tmp = *a;

	if (!tmp)
		return (NULL);
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
		}
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (max == (tmp)->content)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_robio		*min_element(t_robio **a)
{
	int	min;
	t_robio *tmp = *a;

	if (!tmp)
		return (NULL);
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
		}
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (min == (tmp)->content)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);//si la liste est vide
}

int	check_min(t_robio **a)
{
	int	min;
	int min_idx;

	t_robio *tmp = *a;

	if (!tmp)
		return (0);
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