/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:11 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/01 23:14:59 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate(char **dupp)
{
	int		i;
	int		j;

	i = 0;
	while (i < length2d(dupp) - 1) //boucle externe qui parcourt la chaine de caracteres
	{
		j = i + 1;
		while (dupp[j]) //boucle interne qui parcourt la chaine de caracteres a partir de l element suivant
		{
			if (ft_atoi(dupp[i]) == ft_atoi(dupp[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
//le premier pointeur *dupp est un poinetur vers le tableau de chaines de caracteres
//c est a travers ce pointeur que la fonction peut acceder a chaque chaine de caractere du tableau
//en utilisant un double pointeur la fonction peut modifier le tableau