/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:04:11 by brandres          #+#    #+#             */
/*   Updated: 2019/09/21 18:56:44 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*save;
	unsigned int	i;

	save = (unsigned char*)s;
	i = 0;
	while (i < n && n > 0)
	{
		save[i] = 0;
		i++;
	}
}
