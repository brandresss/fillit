/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:56:52 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 23:46:49 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int		i;
	int					res;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	res = 0;
	while (haystack[res] != '\0')
	{
		if (haystack[res] == needle[0])
		{
			i = 1;
			if (needle[i] == '\0')
				return ((char*)&haystack[res]);
			while (haystack[res + i] == needle[i])
			{
				if (needle[i + 1] == '\0')
					return ((char*)&haystack[res]);
				i++;
			}
		}
		res++;
	}
	return (0);
}
