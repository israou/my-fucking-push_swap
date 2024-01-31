/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join4checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:15:59 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/28 21:16:12 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	lenght(char **str, char *del, int size)//longueur totale d une serie de chaines de caracteres str
												//longueur totale du delimiteur
												//le nbre totale de chaines de caracteres (size)
{
	int		i;
	int		l; //longueur totale

	i = 0;
	l = 0;
	while (i < size) //pour parcourir toutes les chaines de str jusqu'a size
	{
		l += ft_strlen(str[i]); // + longueur de la chaine de caractere actuelle a la longueur totale
		i++;
	}
	l += ft_strlen(del) * (size - 1);//longueur du del multipliée par le nbre de delimiteurs necessaire
	return (l);
}

static char		*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char **arg, char *del, int size)//tableau de chaine de caractare, delimiteur , la taille du tableau
{
	char	*result;//chaine de caractere resultante
	int		i;

	i = 0;
	if (size <= 0) //si la taille est inferieure ou egale a zero j alloue la memoire pour une chaine de caractere vide
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[i] = '\0';
		return (result);
	}
	result = (char *)malloc(sizeof(char)*(lenght(arg, del, size) + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	while (i < size)
	{
		ft_strcat(result, arg[i]);
		if (i < size - 1) //si ce n est pas la derniere iteration concatene le delimiteur
			ft_strcat(result, del);
		i++;
	}
	return (result);
}
//cette fonction est plus flexible car elle prend en charge la concatenatiion de plusieurs chaines avec un caractere delimiteur
