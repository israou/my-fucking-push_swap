/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:31 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/16 02:35:37 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    aff(t_robio *stack_a, t_robio *stack_b, int size)
{
    printf("------Start-----\n");
    while (size)
    {
        if (stack_a)
        {
            printf("%d| %d\t", stack_a->content, stack_a->index);
            stack_a = stack_a->next;
        }
        else
        {
            printf("  |   \t");
        }
        if (stack_b)
        {
            printf("%d|", stack_b->content);
            stack_b = stack_b->next;
        }
        size--;
        printf("\n");
    }
    printf("-\t-\na\tb\n");
    printf("------End-----\n");
}


int		check_empty(const char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0') // empty
		return (1);
	while(str[i] == ' ')
	{
		i++; // bzaf dial les espaces
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int		ft_isdigit(char *str)
{
	int i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (1); // Error
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1); // Error
		i++;
	}
	return (0); // True
}

int	is_int(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	while (str[i] == 48)
		i++;
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	if (ft_strlen(str + i) > ft_strlen("+2147483647"))//verifier si la longueur de a chaine est plus longue que la representation int_max
		return (1);
	return (0);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

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
	sorting_five(&head_a, &head_b);
	aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	puts("------------");
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
