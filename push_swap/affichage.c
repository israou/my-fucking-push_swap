/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:55:50 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/02 23:14:38 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aff(t_robio *stack_a, t_robio *stack_b, int size)
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
			printf("  |   \t\t"); // ila makan walou f stack kann lqa |
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
