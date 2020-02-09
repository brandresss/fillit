/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:09:52 by brandres          #+#    #+#             */
/*   Updated: 2019/09/20 19:12:01 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*save;

	i = 0;
	save = (char*)s;
	while (save[i] != '\0')
	{
		if (save[i] == c)
			return (&save[i]);
		else
			i++;
	}
	if (c == '\0')
		return (&save[i]);
	return (0);
}
