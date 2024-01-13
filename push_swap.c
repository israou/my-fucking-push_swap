#include "push_swap.h"

int		check_empty(const char *str)
{
	int		i;
	// int		empty;

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
	if (ft_strlen(str + i) > ft_strlen("+2147483647"))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	t_robio *head = NULL;
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
		ft_lstadd_back(&head, node1);
		i++;
	}
	// printf("before content head == %d\n", head->content);
	// printf("addr == %p\n", &head);
	// 			if (duplicate(head) == 1)
	// 					ft_putstr_fd("Error\n", 2);
	// printf("after content head == %d\n", head->content);
	t_robio *tmp = head;
	while (tmp)
	{
		printf("num == %d\n", tmp->content);
		tmp = tmp->next;
	}
	return 0;
}

t_robio	*ft_lstnew(int content)
{
	t_robio	*node;

	node = malloc(sizeof(t_robio));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_robio	*ft_lstlast(t_robio *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_robio **lst, t_robio *new)
{
	t_robio	*lis;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		lis = ft_lstlast(*lst);
		lis->next = new;
	}
	else
	{
		(*lst) = new;
	}
}