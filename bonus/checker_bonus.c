/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:01:48 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/04 00:08:37 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker_moves(t_robio **a, t_robio **b, char *line)
{
	if (strcompare(line, "sa\n") == 0)
		ft_swap(a);
	else if (strcompare(line, "ss\n") == 0)
		ft_ss(a, b);
	else if (strcompare(line, "ra\n") == 0)
		ft_rotate(a);
	else if (strcompare(line, "rr\n") == 0)
		rr(a, b);
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

char	**pars_one(int ac, char **av)
{
	int		i;
	char	**splitted_args;

	i = 0;
	while (av[++i])
		if (check_empty(av[i]))
			ft_putstr_fd("Error\n", 2);
	splitted_args = ft_split(ft_strjoin(av + 1, " ", ac - 1), ' ');
	if (splitted_args == NULL)
		ft_putstr_fd("Error\n", 2);
	if (duplicate(splitted_args))
		return (free_memory(splitted_args), NULL);
	return (splitted_args);
}

void	ft_check(int ac, char **av, t_robio **a)
{
	int		i;
	char	**splitted_args;
	int		size;
	t_robio	*node1;

	i = 0;
	splitted_args = pars_one(ac, av);
	size = length2d(splitted_args);
	while (splitted_args && splitted_args[i])
	{
		if (ft_isdigit(splitted_args[i]) || is_int(splitted_args[i]))
			break ;
		node1 = ft_lstnew(ft_atoi(splitted_args[i]));
		if (node1 == NULL)
			break ;
		ft_lstadd_back(a, node1);
		i++;
	}
	free_memory(splitted_args);
	if (i < size)
	{
		ft_linkedclear(a);
		ft_putstr_fd("Error\n", 2);
	}
}

int	check_sort(t_robio *a)
{
	if (!a || !a->next)
		return (0);
	while (a && a->next)
	{
		if (a->content > a->next->content)
		{
			return (1);
		}
		a = a->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_robio	*head_a;
	t_robio	*head_b;
	char	*line;

	head_a = NULL;
	head_b = NULL;
	if (ac <= 1)
		return (0);
	ft_check(ac, av, &head_a);
	line = get_next_line(0);
	while (line)
	{
		checker_moves(&head_a, &head_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sort(head_a) == 0 && ft_lstsize(head_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
