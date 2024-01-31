/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:51 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/28 21:08:33 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_swap(t_robio **a)//void hit deja kan sifto **a donc ki t updata f stack
{
	int	tmp;//pske le contenu de t_robio est manipulé comme valeur entiere, content mdeclarer int
	t_robio	*r;

	if (!a || !*a || !(*a)->next)//si a est null, si !*a est null cad kil y a aucun element dans la liste,, si !(*a->next est null cad il y a aucun element suivant dans la liste.)
		return ;
	r = (*a)->next;
	tmp = (*a)->content;
	(*a)->content = r->content;
	r->content = tmp;
	indexmystack(a);
}

void	ft_ss(t_robio **a, t_robio **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_rotate(t_robio **a)
{
	t_robio	*tmp;
	if (!a || !*a || !(*a)->next)//pointeur vers struct null, liste pointée par a est nulle, la liste contient un seul element
		return ;
	tmp = *a;//tmp pointe vers la meme addresse que *a, donc partagent le meme contenu mais ne stocke pas le contenu..
	(*a) = (*a)->next;//update pour a
	tmp->next = NULL;
	ft_lstlast(*a)->next = tmp;
	indexmystack(a);
}

void	rr(t_robio **a, t_robio **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_reverse_rotate(t_robio **a)
{
	t_robio	*tmp;
	t_robio	*tmp1;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = ft_lstlast(*a);
	tmp1 = *a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	ft_lstadd_front(a, tmp);
	indexmystack(a);
}

void	ft_rrr(t_robio **a, t_robio **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);

}

void	push_b(t_robio **a, t_robio **b)
{
	t_robio *tmp;
	if (!*a)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;//l ancien sommet devient tmp li hoa a
	indexmystack(a);
	indexmystack(b);
}

void	push_a(t_robio **b, t_robio **a)
{
	t_robio	*tmp;

	if (!*b)
		return ;
	tmp = (*b);
	(*b)=(*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	indexmystack(a);
	indexmystack(b);
}

void	indexmystack(t_robio **a)
{
	int i;
	t_robio *tmp = (*a);//pointeur vers le premier element

	if (!a || !(*a) || !(*a)->next)
		return ;
	i = 0;
	while (tmp)
	{
		tmp->index = i; //index de chaque noeud
		i++;
		tmp = tmp->next;
	}
}