/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:10:20 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/13 01:12:37 by ichaabi          ###   ########.fr       */
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

#endif