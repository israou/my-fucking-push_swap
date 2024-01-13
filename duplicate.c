#include "push_swap.h"

int		duplicate(char **dupp)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (dupp[i])
	{
		while (dupp[j])
		{
			if (ft_atoi(dupp[i]) == ft_atoi(dupp[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

	// printf("isinde addr == %p\n", &head);
	// t_robio	*node;
	// head->content = 300;
	// head = head->next;
	// printf("inside content head == %d\n", head->content);

	// head->next = node;

