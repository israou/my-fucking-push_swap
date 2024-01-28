/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:02:09 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/28 00:44:48 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_robio
{
	int content;
	int index;
	int move;
	struct s_robio *next;
}t_robio;

t_robio	*ft_lstnew(int content);
t_robio	*ft_lstlast(t_robio *lst);

int		strcompare(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
int		check_empty(const char *str);
int		ft_isdigit(char *str);
int		is_int(char *str);
int		checknewline(char *s);
long	ft_atoi(const char *str);
char	*ft_strdup(char *s);
char	*join4checker(char const *stash, char const *buf);
char	*extraction(char const *s, unsigned int start, size_t len);
char	*divising(char *s, char **reste);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);


void	ft_lstadd_back(t_robio **lst, t_robio *new);
void	indexmystack(t_robio **a);
void	ft_lstadd_front(t_robio **lst, t_robio *new);
int		ft_lstsize(t_robio *lst);

void	ft_swap(t_robio **a);
void	ft_ss(t_robio **a, t_robio **b);
void	ft_rotate(t_robio **a);
void	rarb(t_robio **a, t_robio **b);
void	ft_reverse_rotate(t_robio **a);
void	ft_rrr(t_robio **a, t_robio **b);
void	push_b(t_robio **a, t_robio **b);
void	push_a(t_robio **b, t_robio **a);

int		countword(const char *str, char c);
char	*get_word(const char *s, char c, int *i);
char	**ft_free(char **s);
char	**ft_split(const char *s, char c);

void	checker_moves(t_robio *a, t_robio *b);
void	ft_check(int ac, char **av, t_robio *a);
#endif