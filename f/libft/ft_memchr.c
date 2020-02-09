/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:29:45 by brandres          #+#    #+#             */
/*   Updated: 2019/09/22 16:55:14 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*save;
	size_t			i;
	unsigned char	c1;

	save = (unsigned char*)s;
	c1 = (char)c;
	i = 0;
	while (i < n)
	{
		if (save[i] == c1)
		{
			return (&save[i]);
		}
		i++;
	}
	return (NULL);
}
