/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:11 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/16 17:45:19 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		duplicate(char **dupp)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (dupp[i])
	{
		while (dupp[j])
		{
			if (ft_atoi(dupp[i]) == ft_atoi(dupp[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}