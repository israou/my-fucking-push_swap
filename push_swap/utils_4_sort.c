/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:52:03 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:31:51 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_max(t_robio **a, int *max_idx)
{
	int		max;
	t_robio	*tmp;

	tmp = (*a);
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

int	check_min(t_robio **a)
{
	int		min;
	int		min_idx;
	t_robio	*tmp;

	tmp = *a;
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

t_robio	*max_element(t_robio **a)
{
	int		max;
	t_robio	*tmp;

	tmp = *a;
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

t_robio	*min_element(t_robio **a)
{
	int		min;
	t_robio	*tmp;

	tmp = *a;
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
	return (NULL);
}
