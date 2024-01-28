/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:55:16 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/26 18:10:13 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0') // empty
		return (1);
	while(str[i] == ' ')
		i++; // bzaf dial les espaces
	if (str[i] == '\0')
		return (1);
	return (0);
}

int		ft_isdigit(char *str)
{
	int i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (1); // Error
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1); // Error
		i++;
	}
	return (0); // True
}

int	is_int(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	while (str[i] == 48)
		i++;
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	if (ft_strlen(str + i) > ft_strlen("+2147483647"))//verifier si la longueur de a chaine est plus longue que la representation int_max
		return (1);//str + i on decale i pour pointer vers le premier caractere apres les 0
	return (0);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}
