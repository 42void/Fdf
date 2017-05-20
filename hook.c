/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 20:17:00 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/01/31 19:22:42 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (0);
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65451 || keycode == 65453 ||
		(keycode >= 65361 && keycode <= 65366))
	{
		if (keycode == 65365)
			e->coef_z += 0.1;
		if (keycode == 65366)
			e->coef_z -= 0.1;
		if (keycode == 65361)
			e->origin_x = e->origin_x - 100;
		if (keycode == 65363)
			e->origin_x = e->origin_x + 100;
		if (keycode == 65362)
			e->origin_y = e->origin_y - 100;
		if (keycode == 65364)
			e->origin_y = e->origin_y + 100;
		if (keycode == 65451)
			e->space = e->space + 2;
		if (keycode == 65453)
			if (e->space >= 2)
				e->space = e->space - 2;
		ft_expose_hook(e);
	}
	return (0);
}
