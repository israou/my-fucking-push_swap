/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:20:45 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/13 19:05:36 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// int main()
// {
// 	printf("%d\n", ft_atoi("  j463"));
// 	//printf("%d\n", check_empty_digit("    ", 1));
// }
