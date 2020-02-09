/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:50:17 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 22:03:18 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		lol(char *s, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = len - 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	if (i != len)
	{
		while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ')
		{
			i++;
			j--;
		}
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	copy;
	char			*str;
	size_t			len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = lol((char*)s, len);
	if (!(str = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	j = 0;
	copy = len - i;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	while (j < (copy))
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
