/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:21:32 by brandres          #+#    #+#             */
/*   Updated: 2019/09/22 19:02:58 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		save;
	char	*ss;

	i = 0;
	save = -1;
	ss = (char*)s;
	while (ss[i] != '\0')
	{
		if (ss[i] == c)
			save = i;
		if (ss[i + 1] == '\0' && save != -1)
			return (&ss[save]);
		i++;
	}
	if (c == '\0')
		return (&ss[i]);
	return (0);
}
