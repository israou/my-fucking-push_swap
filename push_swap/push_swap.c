/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:31 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/31 18:41:37 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_robio **a)
{
	t_robio	*head_a;

	head_a = (*a);
	if (ft_lstsize(head_a) == 1)
		return (0);
	if (ft_lstsize(head_a) == 2 && head_a->content > head_a->next->content)
		ft_swap(&head_a, "sa\n");
	return (0);
}

void	ft_parsingcheck(int ac, char **av, t_robio **a)
{
	int		i;

	i = 0;
	if (ac <= 1)
		exit(write(1, "invalid number of arguments\n", 28));
	if (check_empty(av[i]))
		ft_putstr_fd("Error\n", 2);
	i++;
	char **splitted_args = ft_split(ft_strjoin(av + 1, " ", ac - 1), ' ');
	if (splitted_args == NULL)
		ft_putstr_fd("Error\n", 2);
	i = 0;
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
int main(int ac, char **av)
{
	t_robio *head_a;
	t_robio *head_b;
	int i;

	head_a = NULL;
	head_b = NULL;
	i = 0;
	if (ac <= 1)
		return (0);
	ft_parsingcheck(ac, av, &head_a);
	int full_size = ft_lstsize(head_a);
	aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	if (ft_lstsize(head_a) == 1 || ft_lstsize(head_a) == 2)
		check_sort(&head_a);
	if (ft_lstsize(head_a) == 3)
		sorting_three(&head_a);
	if (ft_lstsize(head_a) == 4 || ft_lstsize(head_a) == 5)
		sorting_five(&head_a, &head_b);
	else
		step_by_step(&head_a, &head_b, full_size);
	aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	return 0;
}
