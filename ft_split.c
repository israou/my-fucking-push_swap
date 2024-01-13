/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:57:01 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/13 19:02:06 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countword(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != c)//ignorer les caracteres du mot actuel jusqu'au prohain delimiteur
			i++;
	}
	return (count);
}

static char	*get_word(const char *s, char c, int *i)
{
	char	*ptr;
	int		start;
	int		len;
	int		k;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;//j enregistre la position du debut du mot
	while (s[*i] && s[*i] != c)
		(*i)++;//j'avance jusqu'au prochain caractere delimiteur
	len = *i - start;//calculer la longueur du mot
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	k = 0;
	while (*i - start > k)
	{
		ptr[k] = s[start + k];
		k++;
	}
	ptr[k] = '\0';
	return (ptr); //extraire le mot
}

static char	**ft_free(char **s)//pour liberer la memoire allouee pour un tableu de chaine de caractere;
								//elle utilise free pour liberer la memoire de chaque chaine individuelle dans le tableau
								//puis libere la memoire du tableau lui meme
{
	int		i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);//liberer la memoire du tableau de pointeurs
	return (NULL);
}

char	**ft_spliiiit(const char *s, char c)
{
	char	**res; //tableau de chaines de caracteres
	int		wc;//nbre de mots das la chaine
	int		r;//indice pour parcourir le tableau resultant
	int		i;//suivre la position dans la chaine actuelle

	if (!s)
		return (NULL);
	wc = countword(s, c);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (free((char *)s), NULL);
	r = 0;
	i = 0;
	while (wc > r)
	{
		res[r] = get_word(s, c, &i);
		if (!res[r])
			return (free((char *)s), ft_free(res));
			r++;
	}
	res[wc] = NULL;
	free((char *)s);
	return (res);
}
// int main()
// {
// 	char str[] = "robio 32 ' ' 37 fhdu7 9238 8 3 2";
// 	char **result = ft_spliiiit(str, ' ');
// 	int i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	ft_free(result);
// }