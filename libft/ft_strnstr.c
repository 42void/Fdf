/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:34:54 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/11/09 18:19:31 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*tmp1;
	const char	*tmp2;
	size_t		i;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		tmp1 = s1;
		tmp2 = s2;
		while (*tmp1 == *tmp2 && *tmp1 && *tmp2 && i < n)
		{
			i++;
			tmp1++;
			tmp2++;
		}
		if (!*tmp2)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
