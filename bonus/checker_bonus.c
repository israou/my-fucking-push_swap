/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:01:48 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/28 20:13:24 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker_moves(t_robio *a, t_robio *b, char *line)
{
	// char *line = get_next_line(0);
	if (strcompare(line, "sa\n") == 0)
		ft_swap(a);
	else if (strcompare(line, "ss\n") == 0)
		ft_ss(a, b);
	else if (strcompare(line, "ra\n") == 0)
		ft_rotate(a);
	else if (strcompare(line, "rarb\n") == 0)
		rarb(a, b);
	else if (strcompare(line, "rra\n") == 0)
		ft_reverse_rotate(a);
	else if (strcompare(line, "rrr\n") == 0)
		ft_rrr(a, b);
	else if (strcompare(line, "pb\n") == 0)
		push_b(a, b);
	else if (strcompare(line, "pa\n") == 0)
		push_a(b, a);
	else
		ft_putstr_fd("Error\n", 2);
}

void	ft_check(int ac, char **av, t_robio **a)
{
	int		i;

	i = 0;
	if (ac <= 1)
		exit(write(1, "invalid number of arguments\n", 28));
	if (check_empty(av[i]))
		ft_putstr_fd("Error\n", 2);
	i++;
	i = 0;
	char **splitted_args = ft_split(ft_strjoin(av + 1, " ", ac - 1), ' ');
	if (splitted_args == NULL)
		ft_putstr_fd("Error\n", 2);
	while (splitted_args[i])
	{
		if (ft_isdigit(splitted_args[i]))
			ft_putstr_fd("Error\n", 2);
		if (is_int(splitted_args[i]))
			ft_putstr_fd("Error\n", 2);
		if (duplicate(&splitted_args[i]))
			ft_putstr_fd("Error\n", 2);
		t_robio *node1 = ft_lstnew(ft_atoi(splitted_args[i]));
		ft_lstadd_back(a, node1);
		i++;
	}
}

int		check_sort(t_robio *a)
{
	if (!a || !a->next)
		return (1);
	while (a && a->next)
	{
		if (a->content > a->next->content)
		{
			return (0);
		}
		a = a->next;
	}
	return (1);
}

int main(int ac, char **av)
{
	int i = 0;
	t_robio *head_a = NULL;
	t_robio *head_b = NULL;

	if (ac <= 1)
		return (0);
	ft_check(ac, av, &head_a);
	char *line = get_next_line(0);
	while (line)
	{
		printf("%s", line);
		checker_moves(&head_a, &head_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sort(head_a) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
