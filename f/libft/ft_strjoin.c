/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:41:39 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 23:03:00 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*sj;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	sj = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sj)
		return (NULL);
	while (s1[i] != '\0')
	{
		sj[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		sj[i] = s2[j];
		j++;
		i++;
	}
	sj[i] = '\0';
	return (sj);
}
