/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:09:12 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 16:46:53 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char			*save1;
	char			*save2;
	unsigned char	i;

	i = 0;
	save1 = (char*)s1;
	save2 = (char*)s2;
	if (n == 0)
		return (0);
	while (i < n - 1\
	&& save1[i] == save2[i])
		i++;
	return ((unsigned char)save1[i] - (unsigned char)save2[i]);
}
