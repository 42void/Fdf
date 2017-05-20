/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:20:10 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/11/15 15:10:38 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*ptr_dst;
	const char		*ptr_src;

	i = 0;
	ptr_dst = (char *)dest;
	ptr_src = (const char *)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_dst[i] == (unsigned char)c)
			return (&ptr_dst[i + 1]);
		i++;
	}
	return (0);
}
