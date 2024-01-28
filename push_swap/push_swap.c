/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:31 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/28 21:25:48 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	t_robio *head_a = NULL;
// 	t_robio *head_b = NULL;
// 	if (ac <= 1)
// 		return (0);
// 	while (av[i])
// 	{
// 		if (check_empty(av[i]))
// 			ft_putstr_fd("Error\n", 2);
// 		i++;
// 	}
// 	i = 0;
// 	char **splited_args = ft_split(ft_strjoin(av + 1, " ", ac - 1), ' ');//ac le nbre total d arg -1 excluant le nom du programme ,, av + 1 le 2 eme element du tableau
// 	if (splited_args == NULL)
// 		ft_putstr_fd("Error\n", 2);
// 	while (splited_args[i])
// 	{
// 		if (ft_isdigit(splited_args[i]))
// 			ft_putstr_fd("Error\n", 2);
// 		if (is_int(splited_args[i]))
// 			ft_putstr_fd("Error\n", 2);
// 		if (duplicate(&splited_args[i]))
// 			ft_putstr_fd("Error\n", 2);
// 		t_robio *node1 = ft_lstnew(ft_atoi(splited_args[i]));
// 		ft_lstadd_back(&head_a, node1);
// 		i++;
// 	}
// 	int full_size = ft_lstsize(head_a);
// 	aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
// 	if (ft_lstsize(head_a) == 1)
// 		return (0);
// 	if (ft_lstsize(head_a) == 2 && head_a->content > head_a->next->content)
// 		ft_swap(&head_a, "sa\n");
// 	if (ft_lstsize(head_a) == 3)
// 		sorting_three(&head_a);
// 	if (ft_lstsize(head_a) == 4 || ft_lstsize(head_a) == 5)
// 		sorting_five(&head_a, &head_b);
// 	else
// 		step_by_step(&head_a, &head_b, full_size);
// 	aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
// 	// while (head_a && head_a->next)
// 	// {
// 	// 	if (head_a->content > head_a->next->content)
// 	// 	{
// 	// 		puts("FUCKEDUP");
// 	// 		exit(0);
// 	// 	}
// 	// 	head_a = head_a->next;
// 	// }
// 	return 0;
// }
