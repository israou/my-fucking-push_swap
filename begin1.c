/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:08:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/13 00:39:03 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

// long	ft_atoi(const char *str)
// {
// 	long		i;
// 	long		sign;
// 	long	numb;

// 	i = 0;
// 	sign = 1;
// 	numb = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		numb = (numb * 10) + (str[i] - 48);
// 		i++;
// 	}
// 	return (sign * numb);
// }

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


// void	ft_putchar_fd(int i, int fd)
// {
// 	write(fd, &i, 1);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n < 0)
// 	{
// 		ft_putchar('-', fd);
// 		n *= -1;
// 	}
// 	if (n > 9)
// 	{
// 		ft_putnbr(n / 10, fd);
// 	}
// 	ft_putchar_fd(n % 10 + '0', fd);
// }


// int		is_alpha(int i)
// {
// 	if (i >= 'a' && i <= 'z')
// 		exit(write(1, "Error\n", 6));
// 	r
// }
// int main()
// {
// 	char t[] = "abcd";
// 	char t1[] = "ab1d";

// 	if (strcompare(t, t1) == 0)
// 		puts("True");
// 	else
// 		puts("False");

// }