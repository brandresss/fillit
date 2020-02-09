/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:13:19 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 15:24:58 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	save;

	i = 0;
	j = 0;
	save = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (i >= size)
		j = j + size;
	else
		j = j + i;
	while (src[save] != '\0' && size > i + 1)
	{
		dst[i] = src[save];
		i++;
		save++;
	}
	dst[i] = '\0';
	return (j);
}
