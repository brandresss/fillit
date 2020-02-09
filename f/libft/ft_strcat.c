/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:57:05 by brandres          #+#    #+#             */
/*   Updated: 2019/09/20 19:53:19 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *destptr, const char *srcptr)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	while (destptr[i] != '\0')
		i++;
	if (destptr[i] == '\0')
		while (srcptr[j] != '\0')
		{
			destptr[i] = srcptr[j];
			i++;
			j++;
		}
	destptr[i] = '\0';
	return (destptr);
}
