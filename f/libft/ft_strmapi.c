/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:43:42 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 23:04:16 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		map[i] = f(i, s1[i]);
		i++;
	}
	return (map);
}
