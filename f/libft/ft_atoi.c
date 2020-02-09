/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:31:10 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 20:40:54 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned long long	ft_ooo(const char *str, int sign)
{
	unsigned long long	save;
	size_t				i;

	i = 0;
	save = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		save = (str[i] - '0') + (save * 10);
		i++;
	}
	if (sign == -1)
	{
		if (save >= 9223372036854775807)
			return (0);
		return (save);
	}
	if (save >= 9223372036854775807)
		return (-1);
	return (save);
}

int							ft_atoi(const char *str)
{
	int					i;
	unsigned long long	save;
	int					sign;

	i = 0;
	sign = 1;
	save = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && sign > 0)
		i++;
	save = ft_ooo(str + i, sign);
	return (sign * (int)save);
}
