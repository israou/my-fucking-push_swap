/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:08:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/17 13:14:52 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int		strcompare(const char *s1, const char *s2)
{
	int i = 0;

	while(s2[i])
	{
		if(s1[i] != s2[i])
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
		exit(write(fd, "Error\n", 6));
	while (str[i])
		write(fd, &str[i++], 1);
}

void	ft_putchar_fd(int i, int fd)
{
	write(fd, &i, 1);
}
