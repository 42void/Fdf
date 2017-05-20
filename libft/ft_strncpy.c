/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:13:14 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/11/09 19:45:22 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (ft_strlen(src) <= n)
	{
		while (i < n)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
