/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:34 by brandres          #+#    #+#             */
/*   Updated: 2019/09/21 17:17:32 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*save;
	unsigned int	i;
	unsigned char	c1;

	save = (unsigned char*)b;
	c1 = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		save[i] = c1;
		i++;
	}
	return (save);
}
