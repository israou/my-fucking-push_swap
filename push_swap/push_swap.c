/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:31 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/02 22:49:11 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void l()
{
	system("leaks push_swap");
}

char	**pars_one(int ac, char **av)
{
	int	i;
	char **splitted_args;

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

int	check_sort(t_robio **a)
{
	t_robio	*head_a;

	head_a = (*a);
	int i = ft_lstsize(head_a);

	if (ft_lstsize(head_a) == 1)
		return (0);
	else if (ft_lstsize(head_a) == 2 && head_a->content > head_a->next->content)
		ft_swap(&head_a, "sa\n");
	while (i > 1)
	{
		if (head_a->content < head_a->next->content)
			head_a = head_a->next;
		i--;
	}
	if (head_a->next == NULL)
	{
		ft_lstclear(a);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
int	length2d(char **splitted_args)
{
	int	i;

	i = 0;
	if (!splitted_args)
		return (1);
	while (splitted_args[i])
		i++;
	return (i);
}
void	ft_parsingcheck(int ac, char **av, t_robio **a)
{
	int	i;
	char **splitted_args;
	int	size;

	i = 0;
	splitted_args = pars_one(ac, av);
	size = length2d(splitted_args);
	while (splitted_args && splitted_args[i])//larray lkbir wch kayn,, ldakhel kayn
	{
		if (ft_isdigit(splitted_args[i]) || is_int(splitted_args[i]))
			break ;//khasso yclearer dakshy li qbel
		t_robio *node1 = ft_lstnew(ft_atoi(splitted_args[i]));
		if (node1 == NULL)//par exemple ila node 4 khesrat
			break ;
		ft_lstadd_back(a, node1);
		i++;
	}
	free_memory(splitted_args);//kan freer splitted args hit m allokia
	if (i < size)
	{
		ft_lstclear(a);//iclearer dakshy li qbel
		ft_putstr_fd("Error\n", 2);
	}

}

int main(int ac, char **av)
{
	// atexit(l);
	t_robio	*head_a;
	t_robio	*head_b;
	int		i;

	head_a = NULL;
	head_b = NULL;
	i = 0;
	if (ac <= 1)
		// ft_putstr_fd("Error\n", 2);
		return (0);
	ft_parsingcheck(ac, av, &head_a);
	// aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	check_sort(&head_a);
	if (ft_lstsize(head_a) == 3)
		sorting_three(&head_a);
	else if (ft_lstsize(head_a) == 4 || ft_lstsize(head_a) == 5)
		sorting_five(&head_a, &head_b);
	else
		step_by_step(&head_a, &head_b, ft_lstsize(head_a));
	// aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	return 0;
}
