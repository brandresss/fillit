/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frre.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofya_stepanova <sofya_stepanova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:48:30 by brandres          #+#    #+#             */
/*   Updated: 2020/02/21 21:33:38 by sofya_stepa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	max_y(char *koord)
{
	int		i;
	char	tmp;

	i = 0;
	while (i <= 6)
	{
		if (tmp < koord[i])
			tmp = koord[i];
		i += 2;
	}
	return (tmp);
}

char	max_x(char *koord)
{
	int		j;
	char	tmp;

	j = 1;
	while (j <= 7)
	{
		if (tmp < koord[j])
			tmp = koord[j];
		j += 2;
	}
	return (tmp);
}

char	*koordin(char *buf)
{
	int		i;
	int		j;
	char	*koord;

	koord = (char *)malloc(sizeof(char) * 9);
	koord[8] = '\0';
	i = 0;
	j = 0;
	while (i <= 19)
	{
		if (buf[i] == '#')
		{
			koord[j] = i / 5 + '0';
			koord[j + 1] = i % 5 + '0';
			j += 2;
		}
		i++;
	}
	return (koord);
}

char	*null_pos(char *koord)
{
	int		i;
	int		c;
	int		j;
	int		tmp;

	i = 0;
	j = 1;
	c = 3;
	while (i <= 6)
	{
		if (c > koord[i] - '0')
			c = koord[i] - '0';
		i += 2;
	}
	tmp = 3;
	while (j <= 7)
	{
		if (tmp > koord[j] - '0')
			tmp = koord[j] - '0';
		j += 2;
	}
	//printf("c tmp:%d %d\n", c, tmp);
	j = 1;
	while (j <= 7)
	{
		koord[j] = koord[j] - tmp;
		j += 2;
	}
	i = 0;
	while (i <= 6)
	{
		koord[i] = koord[i] - c;
		i += 2;
	}
	return (koord);
}
