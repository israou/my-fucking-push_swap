/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:10:20 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/26 20:55:33 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H



# ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h> //malloc
# include <stddef.h> //size_t
# include <limits.h> //int_max int_min

typedef struct s_robio
{
	int	content;
	int	index;
	int move;
	struct s_robio *next;
} t_robio;

int		ft_strlen(const char *s);
int	check_empty(const char *str);
int		ft_isdigit(char *str);
int	is_int(char *str);
int	ft_max(int x, int y);
char	*ft_strjoin(char **arg, char *del, int size);
int		strcompare(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(const char *s, char c);
long	ft_atoi(const char *str);
t_robio	*ft_lstnew(int content);
void	ft_lstadd_back(t_robio **lst, t_robio *new);
t_robio	*ft_lstlast(t_robio *lst);
int		duplicate(char **dupp);
void	ft_swap(t_robio **a, char *str);
void	ft_ss(t_robio **a, t_robio **b, char *str);
void	ft_rotate(t_robio **a, char *str);
void	rarb(t_robio **a, t_robio **b, char *str);
void	ft_reverse_rotate(t_robio **a, char *str);
void	ft_rrr(t_robio **a, t_robio **b, char *str);
void	ft_lstadd_front(t_robio **lst, t_robio *new);
void	push_b(t_robio **a, t_robio **b, char *str);
void	push_a(t_robio **b, t_robio **a, char *str);
int		ft_lstsize(t_robio *lst);
void	indexmystack(t_robio **a);
void	sorting_three(t_robio **a);
void	check_max(t_robio **a, int *max_idx);
int		check_min(t_robio **a);
void	sorting_five(t_robio **a, t_robio **b);
t_robio	*get_top(t_robio *a, t_robio *b);
int		get_min_move(t_robio *b, t_robio *top, int size_a, int size_b);

void	step_by_step(t_robio **a, t_robio **b, int size);
t_robio	*max_element(t_robio **a);
t_robio	*min_element(t_robio **a);
//////////////////  Affichage  ////////////////////

void	aff(t_robio *stack_a, t_robio *stack_b, int size);
int		ft_max(int x, int y);

//moves//
void	two_up(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best);
void	two_down(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best);
void	up_down(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best);
void	down_up(t_robio **a, t_robio **b, t_robio *top_a, t_robio *best);
int	type_of_move(t_robio *elm_b, t_robio *elm_a, t_robio *a, t_robio *b);

//checker//
char	*divising(char *s, char **reste);
char	*get_next_line(int fd);
int	checknewline(char *s);
char	*ft_strdup(char *s);
char	*join4checker(char const *stash, char const *buf);
char	*extraction(char const *s, unsigned int start, size_t len);


#endif