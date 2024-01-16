int main(int ac, char **av)
{
	int i = 0;
	t_robio *head_a = NULL;
	t_robio *head_b = NULL;
	if (ac <= 1)
		return (0);
	while (av[i])
	{
		if (check_empty(av[i]))
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	i = 0;
	char **splited_args = ft_spliiiit(ft_strjoin(av + 1, " ", ac - 1), ' ');
	if (splited_args == NULL)
			ft_putstr_fd("Error\n", 2);
	while (splited_args[i])
	{
		if (ft_isdigit(splited_args[i]))
			ft_putstr_fd("Error\n", 2);
		if (is_int(splited_args[i]))
			ft_putstr_fd("Error\n", 2);
		if (duplicate(&splited_args[i]))
			ft_putstr_fd("Error\n", 2);
		t_robio *node1 = ft_lstnew(ft_atoi(splited_args[i]));
		ft_lstadd_back(&head_a, node1);
		i++;
	}
	aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	if (ft_lstsize(head_a) <= 3)
		sorting_three(&head_a);
	else if (ft_lstsize(head_a) <= 5)
		sorting_five(&head_a, &head_b);
	else
		// bigsort
	aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	puts("-----------------");
	// int min_idx, max_idx;
	// check_max_min(&head_a, &min_idx, &max_idx);
	// printf("max_idx: %d | min_idx:%d\n", max_idx, min_idx);
	// printf("\nswap\n");
	// ft_swap(&head_a);
	// tmp = head_a;
	// while (tmp)
	// {
	// 	printf("%d | ", tmp->content);
	// 	printf("index: %d\n", tmp->index);
	// 	tmp = tmp->next;
	// }
	// printf("\nrotate\n");
	// ft_rotate(&head_a);
	// tmp = head_a;
	// while (tmp)
	// {
	// 	printf("%d | ", tmp->content);
	// 	printf("index: %d\n", tmp->index);
	// 	tmp = tmp->next;
	// }
	// printf("\nreverserotate\n");
	// ft_reverse_rotate(&head_a);
	// tmp = head_a;
	// while (tmp)
	// {
	// 	printf("%d | ", tmp->content);
	// 	printf("index: %d\n", tmp->index);
	// 	tmp = tmp->next;
	// }
	// printf("\npush_b\n");
	// push_b(&head_a, &head_b);
	// push_b(&head_a, &head_b);
	// tmp = head_b;
	// while (tmp)
	// {
	// 	printf("%d | ", tmp->content);
	// 	printf("index: %d\n", tmp->index);
	// 	tmp = tmp->next;
	// }
	// printf("\npush_a\n");
	// push_a(&head_b, &head_a);
	// push_a(&head_b, &head_a);
	// tmp = head_a;
	// while (tmp)
	// {
	// 	printf("%d | ", tmp->content);
	// 	printf("index: %d\n", tmp->index);
	// 	tmp = tmp->next;
	// }
	return 0;
}
