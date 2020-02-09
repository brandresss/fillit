/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:58:57 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 16:18:19 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*save;
	unsigned char	*save1;
	unsigned char	c1;
	unsigned int	i;

	i = 0;
	c1 = (unsigned char)c;
	save = (unsigned char*)dst;
	save1 = (unsigned char*)src;
	while (i < n && n > 0)
	{
		save[i] = save1[i];
		if (save1[i] == c1)
		{
			return (&save[i + 1]);
		}
		i++;
	}
	return (NULL);
}
