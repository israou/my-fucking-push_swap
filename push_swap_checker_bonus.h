/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:06:08 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/23 21:14:14 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_BONUS_H
# define PUSH_SWAP_CHECKER_BONUS_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdlib.h>
# include <limits.h>

int		strcompare(const char *s1, const char *s2);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
long	ft_atoi(const char *str);
int		duplicate(char **dupp);
int		check_empty(const char *str);
int		ft_isdigit(char *str);
int		is_int(char *str);
int		checknewline(char *s);
char	*divising(char *s, char **reste);
char	*get_next_line(int fd);
char	*extraction(char const *s, unsigned int start, size_t len);


#endif