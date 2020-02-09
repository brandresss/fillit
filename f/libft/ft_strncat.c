/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:55:27 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 23:15:51 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		while (j < n && s2[j] != '\0')
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
	s1[i] = '\0';
	return (s1);
}
