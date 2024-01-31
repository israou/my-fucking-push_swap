/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:40:19 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/29 21:09:27 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_empty(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0') // empty
		return (1);
	while (str[i] == ' ')
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

long	ft_atoi(const char *str)
{
	long		i;
	long		sign;
	long	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (numb * 10) + (str[i] - 48);
		i++;
	}
	return (sign * numb);
}
