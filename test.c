//operations

#include "push_swap.h"

void	ft_swap(t_robio **a, char *str)
{
	int	tmp;//pske le contenu de t_robio est manipulé comme valeur entiere, content mdeclarer int
	t_robio	*r;

	if (!a || !*a || !(*a)->next)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = (*a)->content;
	r = (*a)->next;
	(*a)->content = r->content;
	r->content = tmp;
}

void	ft_rotate(t_robio **a, char *str)
{
	t_robio *tmp;
	if (!a || !*a || !(*a)->next)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = *a;//tmp pointe sur la meme adresse que *a
	(*a) = (*a)->next;//update pour a , deplacer le pointeur vers le prochain element
	ft_lstlast(*a)->next = tmp;//relier next de last a tmp
	tmp->next = NULL;// sassurer que l ancien premier placé a la fin mtn pointe vers null
}

void	ft_reverse_rotate(t_robio **a, char *str)
{
	t_robio	*tmp;
	t_robio *tmp1;
	if (!a || !*a || !(*a)->next)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = ft_lstlast(*a);
	while (tmp1->next->next)//tant que l element suivant de l element suivant
		tmp1 = tmp1->next;//continue a iterer
	tmp1->next = NULL;
	ft_lstadd_front(a, tmp);
}

void	ft_push(t_robio **a, t_robio **b, char *str)
{
	t_robio *tmp;
	if (!*a)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;//l ancien sommet devient tmp
}