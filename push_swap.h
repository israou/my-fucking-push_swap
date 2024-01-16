/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:10:20 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/16 02:34:52 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> //malloc
#include <stddef.h> //size_t
#include <limits.h> //int_max int_min

typedef struct s_robio
{
	int	content;
	int	index;
	struct s_robio *next;
} t_robio;

int		ft_strlen(char *s);
char	*ft_strjoin(char **arg, char *del, int size);
int		strcompare(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
char	**ft_spliiiit(const char *s, char c);
long	ft_atoi(const char *str);
t_robio	*ft_lstnew(int content);
void	ft_lstadd_back(t_robio **lst, t_robio *new);
t_robio	*ft_lstlast(t_robio *lst);
int		duplicate(char **dupp);
void	ft_swap(t_robio **a);
void	ft_ss(t_robio **a, t_robio **b);
void	ft_rotate(t_robio **a);
void	rarb(t_robio **a, t_robio **b);
void	ft_reverse_rotate(t_robio **a);
void	ft_rrr(t_robio **a, t_robio **b);
void	ft_lstadd_front(t_robio **lst, t_robio *new);
void	push_b(t_robio **a, t_robio **b);
void	push_a(t_robio **b, t_robio **a);
int		ft_lstsize(t_robio *lst);
void	indexmystack(t_robio **a);
void	sorting_three(t_robio **a);
void	check_max(t_robio **a, int *max_idx);
int		check_min(t_robio **a);
void	sorting_five(t_robio **a, t_robio **b);

//////////////////  Affichage  ////////////////////

void    aff(t_robio *stack_a, t_robio *stack_b, int size);
int		ft_max(int x, int y);

#endif