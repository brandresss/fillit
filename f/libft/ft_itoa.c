/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:02:20 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 17:04:41 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*jjaba(int n)
{
	char	*str1;
	int		i;

	i = 10;
	str1 = (char*)malloc(sizeof(char) * (11 + 1));
	if (!str1)
		return (NULL);
	str1[11] = '\0';
	str1[0] = '-';
	str1[1] = '2';
	n = 147483648;
	while (n >= 10)
	{
		str1[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (n < 10)
		str1[i] = n + '0';
	return (str1);
}

static	int		boro(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*save;
	int		len;

	if (n == -2147483648)
		return (jjaba(n));
	len = boro(n);
	save = (char*)malloc(sizeof(char) * (len + 1));
	if (!save)
		return (NULL);
	if (n < 0)
	{
		save[0] = '-';
		n *= -1;
	}
	save[len] = '\0';
	len--;
	while (n >= 10)
	{
		save[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (n < 10)
		save[len] = n + '0';
	return (save);
}
