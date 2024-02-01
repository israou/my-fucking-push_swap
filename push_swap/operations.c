/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:10:49 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/01 22:20:23 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_robio **a, char *str)//void hit deja kan sifto **a donc ki t updata f stack
{
	int	tmp;//pske le contenu de t_robio est manipulé comme valeur entiere, content mdeclarer int
	t_robio	*r;

	if (!a || !*a || !(*a)->next)//si a est null, si !*a est null cad kil y a aucun element dans la liste,, si !(*a->next est null cad il y a aucun element suivant dans la liste.)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	r = (*a)->next;
	tmp = (*a)->content;
	(*a)->content = r->content;
	r->content = tmp;
	indexmystack(a);
}

void	ft_ss(t_robio **a, t_robio **b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ft_swap(a, NULL);
	ft_swap(b, NULL);
}

void	ft_rotate(t_robio **a, char *str)
{
	t_robio	*tmp;
	// t_robio	*tmp2;
	if (!a || !*a || !(*a)->next)//pointeur vers struct null, liste pointée par a est nulle, la liste contient un seul element
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = *a;//tmp pointe vers la meme addresse que *a, donc partagent le meme contenu mais ne stocke pas le contenu..
	(*a) = (*a)->next;//update pour a
	tmp->next = NULL;
	ft_lstlast(*a)->next = tmp;
	indexmystack(a);
	// free(tmp);
}

void	rr(t_robio **a, t_robio **b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
}

void	ft_reverse_rotate(t_robio **a, char *str)
{
	t_robio	*tmp;
	t_robio	*tmp1;

	if (!a || !*a || !(*a)->next)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = ft_lstlast(*a);
	tmp1 = *a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	ft_lstadd_front(a, tmp);
	indexmystack(a);
	// free(tmp1);
	// free(tmp);
}

void	ft_rrr(t_robio **a, t_robio **b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ft_reverse_rotate(a, NULL);
	ft_reverse_rotate(b, NULL);

}

void	push_b(t_robio **a, t_robio **b, char *str)
{
	t_robio *tmp;
	if (!*a)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;//l ancien sommet devient tmp li hoa a
	indexmystack(a);
	indexmystack(b);
	// free(tmp);
}

void	push_a(t_robio **b, t_robio **a, char *str)
{
	t_robio	*tmp;

	if (!*b)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	tmp = (*b);
	(*b)=(*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	indexmystack(a);
	indexmystack(b);
	// free(tmp);
}
