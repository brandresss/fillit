/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:27:49 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 23:03:34 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	size_t	i;
	size_t	d;
	char	*s1;

	if (!s || !(*f))
		return (NULL);
	i = 0;
	s1 = (char*)s;
	map = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!map)
		return (NULL);
	d = ft_strlen(s1);
	map[d] = '\0';
	while (i < d)
	{
		map[i] = f(s1[i]);
		i++;
	}
	return (map);
}
