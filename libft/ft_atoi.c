/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:29:24 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/01/31 19:42:52 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	i = 0;
	ret = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-' ? -1 : 1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret = ret * 10 + (str[i] - 48);
		else
			break ;
		i++;
	}
	return (sign * ret);
}
