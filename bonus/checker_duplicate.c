/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:51:42 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/03 23:19:57 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	duplicate(char **dupp)
{
	int		i;
	int		j;

	i = 0;
	while (i < length2d(dupp) - 1)
	{
		j = i + 1;
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
