/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:02:22 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 16:44:51 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*save;
	unsigned char	*save1;
	size_t			i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	save = (unsigned char*)dst;
	save1 = (unsigned char*)src;
	if (save1 < save)
	{
		while (len)
		{
			len--;
			save[len] = save1[len];
		}
		return (save);
	}
	while (i < len)
	{
		save[i] = save1[i];
		i++;
	}
	return (save);
}
