/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 23:31:47 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/01/31 19:43:14 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	unsigned char uc;

	uc = (unsigned char)c;
	return (uc == '\t' || uc == '\n' || uc == '\r' || uc == ' '	\
	|| uc == '\v' || uc == '\f' ? 1 : 0);
}
