/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:03:13 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 16:06:47 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*save;
	char			*save1;
	unsigned int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	save = (char*)dst;
	save1 = (char*)src;
	i = 0;
	while (i < n)
	{
		save[i] = save1[i];
		i++;
	}
	return (save);
}
