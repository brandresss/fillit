/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:41:24 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 21:08:07 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char				*str;
	unsigned int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
