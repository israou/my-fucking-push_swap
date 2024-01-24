/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:54:13 by ichaabi           #+#    #+#             */
/*   Updated: 2024/01/23 21:14:04 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker_bonus.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		strcompare(const char *s1, const char *s2)
{
	int i = 0;

	while(s2[i])
	{
		if(s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	if (strcompare(str, "Error\n") == 0)
		exit(write(fd, "Error\n", 6));
	while (str[i])
		write(fd, &str[i++], 1);
}

long	ft_atoi(const char *str)
{
	long		i;
	long		sign;
	long	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (numb * 10) + (str[i] - 48);
		i++;
	}
	return (sign * numb);
}

int		duplicate(char **dupp)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (dupp[i])//boucle externe qui parcoure la chaine de caractere
	{
		while (dupp[j])//boucle interne qui parcourt la chaine de caractere a partir de l element suivant
		{
			if (ft_atoi(dupp[i]) == ft_atoi(dupp[j]))//si les nombres convertis dans la chaine sont egaux alors il y a un doublons
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_empty(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0') // empty
		return (1);
	while(str[i] == ' ')
		i++; // bzaf dial les espaces
	if (str[i] == '\0')
		return (1);
	return (0);
}

int		ft_isdigit(char *str)
{
	int i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (1); // Error
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1); // Error
		i++;
	}
	return (0); // True
}

int	is_int(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	while (str[i] == 48)
		i++;
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	if (ft_strlen(str + i) > ft_strlen("+2147483647"))//verifier si la longueur de a chaine est plus longue que la representation int_max
		return (1);//str + i on decale i pour pointer vers le premier caractere apres les 0
	return (0);
}
/////////////GET NEXT LINE\\\\\\\\\\

int	checknewline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	else
		return (-1);
}
char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*pa;

	i = 0;
	len = ft_strlen(s);
	pa = (char *)malloc(sizeof(char) * (len + 1));
	if (!pa)
		return (NULL);
	while (i < len)
	{
		pa[i] = s[i];
		i++;
	}
	pa[i] = '\0';
	return (pa);
}

char	*ft_strjoin(char const *stash, char const *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (ft_strdup((char *)buf)); //STASH FLWL KIJI NULL NREJEE LCONTENU D buf F STASH, bash ihet dakshy dial buf f stash
	line = (char *)malloc (sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (line == NULL)
		return (NULL);
	while (stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	while (buf[j])
	{
		line[i + j] = buf[j];
		j++;
	}
	line[i + j] = '\0';
	free((char *) stash); //STASH LMERA TANYA M ALLOKER W KHASNNI NHET FIH DATA JDIDA NFREEYER STASH LQDIM
	return (line);
}

char	*extraction(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = (char *) malloc (sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
char	*divising(char *s, char **reste)
{
	char	*line;
	char	*tmp;
	int		newindex;

	if (!s)
		return (NULL);
	if (*reste && **reste == '\0')
	{
		free(*reste);
		*reste = NULL;
		return (NULL);
	}
	//F HALAT MABQA F LRESTE WALOU BASH NHBES LOOP DIAL LMAIN
	newindex = checknewline(s);
	if (newindex == -1)
	{
		line = ft_strdup(s); //duppliquer la chaine s et la considerer comme une ligne
		free(*reste);
		*reste = ft_strdup("\0"); //initialiser la partie restante a une chaine vide
		return (line);
	}
	tmp = s; //sauvegarde l'adresse de la chaine d'origine
	line = extraction(s, 0, newindex + 1);//extraction de la sous chaine du debut jusqu'au '\n'
	*reste = extraction(s, newindex + 1, ft_strlen(s + newindex)); //extraction de la chaine restante apres le '\n' ignorer lign li deja khdit
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	ssize_t		readd; //resulat de read
	static char	*stash; //apres buf

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || BUFFER_SIZE >= INT_MAX) //verification de la validite de fd; si <1 ou depasse la limite max
		return (NULL); //ela qbel +1 bash mayoverflowish
	buf = malloc(BUFFER_SIZE + 1);
	while (BUFFER_SIZE > 0)
	{
		readd = read(fd, buf, BUFFER_SIZE);
		if (readd == 0) //read a atteint la fin de fd
			return (free(buf), divising(stash, &stash));
		else if (readd == -1)
		{
			free(stash);
			stash = NULL;
			return (free(buf), NULL);
		}
		buf[readd] = '\0';
		stash = ft_strjoin(stash, buf); //concatenation de buf dans stash
		if (checknewline(stash) >= 0) //s'il contient \n
			return (free(buf), divising(stash, &stash));
	}
}