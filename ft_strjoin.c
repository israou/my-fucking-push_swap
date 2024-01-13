/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:54:49 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/13 19:05:23 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		lenght(char **str, char *del, int size)//longueur totale d une serie de chaines de caracteres str
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
	char	*israa;//chaine de caractere resultante
	int		i;

	i = 0;
	if (size <= 0) //si la taille est inferieure ou egale a zero j alloue la memoire pour une chaine de caractere vide
	{
		israa = malloc(sizeof(char));
		if (!israa)
			return (NULL);
		israa[i] = '\0';
		return (israa);
	}
	israa = (char *)malloc(sizeof(char)*(lenght(arg, del, size) + 1));
	if (!israa)
		return (NULL);
	israa[i] = '\0';
	while (i < size)
	{
		ft_strcat(israa, arg[i]);
		if (i < size - 1) //si ce n est pas la derniere iteration concatene le delimiteur
			ft_strcat(israa, del);
		i++;
	}
	return (israa);
}
// int main()
// {
// 	char *arr[] = {"23", "54", "6", "hif", "'  '"};
// 	char *delimiter = " ";
// 	int array_size = sizeof(arr) / sizeof(arr[0]);
// 	char *result = ft_strjoin(arr, delimiter, array_size);
// 	printf("Result: $%s$\n", result);
// 	free(result);
// 	return 0;
// }
