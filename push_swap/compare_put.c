/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 04:17:34 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/29 21:03:22 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strcompare(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	if (strcompare(str, "Error\n") == 0)
	{
		write(fd, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (str[i])
		write(fd, &str[i++], 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
