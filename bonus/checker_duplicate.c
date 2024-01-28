/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:51:42 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/27 16:51:51 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int		duplicate(char **dupp)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (dupp[i])//boucle externe qui parcoure la chaine de caractere
	{
		while (dupp[j])//boucle interne qui parcourt la chaine de caractere a partir de l element suivant
		{
			if (ft_atoi(dupp[i]) == ft_atoi(dupp[j]))//si les nombres convertis dans la chaine sont egaux alors il y a un doublons
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}