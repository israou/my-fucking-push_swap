/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:15:45 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/14 01:27:35 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
static	void	checking(int nb, char *str, int i)
{


}
static	int	ft_sign(int sign)

{
	if (sign > 0)
		return (-1);
	return (0);
}
int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (exit(1), 1);//si un autre + ou - est rencontré apres le signe le programme quitte avec le code d erreur 1
	while (str[i] >= '0' && str[i] <= '9')
	{
		//if ((number > 9223372036854775807ULL) || (number == 9223372036854775807ULL))
		//	return (ft_sign(sign));
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (exit(1), 1);//si un autre + ou - est rencontré apres la conversion du nombre le programme quitte
	return (sign * number);
}

// void	ft_reverse_rotate(t_robio **a)
// {
// 	t_robio	*tmp;
// 	t_robio	*tmp1;
// 	// t_robio *qbeltmp;

// 	if (!a || !*a || !(*a)->next)
// 		return ;
// 	tmp = ft_lstlast(*a);
// 	tmp1 = *a;
// 	// qbeltmp = ft_9bllstlast(*a);
// 	// tmp->next = (*a);
// 	while (tmp1->next->next)
// 		tmp1= tmp1->next;
// 	tmp1->next = NULL;
// 	// qbeltmp->next->next = NULL;
// 	ft_lstadd_front(a, tmp);
// 	(*a) = tmp;
// }