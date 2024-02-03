/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:08:17 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/04 00:08:46 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	length2d(char **splitted_args)
{
	int	i;

	i = 0;
	if (!splitted_args)
		return (1);
	while (splitted_args[i])
		i++;
	return (i);
}
