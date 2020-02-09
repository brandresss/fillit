/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:44:25 by brandres          #+#    #+#             */
/*   Updated: 2019/09/26 23:12:38 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strc;
	int		len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	strc = (char*)malloc(sizeof(char) * (len + 1));
	if (!strc)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		strc[len] = s1[len];
		len++;
	}
	strc[len] = '\0';
	return (strc);
}
