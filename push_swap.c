/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:31 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/18 01:50:34 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    aff(t_robio *stack_a, t_robio *stack_b, int size)
{
    printf("------Start------\n");
    printf("elm - indx\telm - move\n");
    while (size)
    {
        if (stack_a)
        {
            printf("%4d| %d\t\t", stack_a->content, stack_a->index);
            stack_a = stack_a->next;
        }
        else
        {
            printf("  |   \t\t"); // ila makan walou f stack kann lqa |
        }
        if (stack_b)
        {
            printf("%4d|  %d", stack_b->content, stack_b->move);
            stack_b = stack_b->next;
        }
        size--;
        printf("\n");
    }
    printf("  -\t\t\t-\n  a\t\t\tb\n");
    printf("------ End ------\n");
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
		return (1);//str + i on decale i pour pointer vers le premier caractere apres les 0
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
	char **splited_args = ft_spliiiit(ft_strjoin(av + 1, " ", ac - 1), ' ');//ac le nbre total d arg -1 excluant le nom du programme ,, av + 1 le 2 eme element du tableau
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
	int full_size = ft_lstsize(head_a);
	// aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	if (ft_lstsize(head_a) <= 3)
		sorting_three(&head_a);
	else if (ft_lstsize(head_a) <= 5)
		sorting_five(&head_a, &head_b);
	else
		step_one(&head_a, &head_b, full_size);

	// aff(head_a, head_b, ft_max(ft_lstsize(head_a), ft_lstsize(head_b)));
	return 0;
}
