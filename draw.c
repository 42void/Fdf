/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 16:30:37 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/01/31 21:09:30 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fill_struct(t_var_draw *d, t_env *e, t_temp coord)
{
	d->x0 = coord.x0 * e->space;
	d->x1 = coord.x1 * e->space;
	d->y0 = coord.y0 * (e->space / 2);
	d->y1 = coord.y1 * (e->space / 2);
	d->dx = abs(d->x1 - d->x0);
	d->sx = d->x0 < d->x1 ? 1 : -1;
	d->dy = abs(d->y1 - d->y0);
	d->sy = d->y0 < d->y1 ? 1 : -1;
	d->err = (d->dx > d->dy ? d->dx : -d->dy) / 2;
}

static void	ft_draw_line(t_env *e, t_temp coord)
{
	t_var_draw	d;

	ft_fill_struct(&d, e, coord);
	while (1)
	{
		if (d.x0 + e->origin_x >= 0 && d.x0 + e->origin_x <= S_SCREEN_WIDTH &&
			d.y0 + e->origin_y >= 0 && d.y0 + e->origin_y <= S_SCREEN_HEIGHT)
			mlx_pixel_put(e->mlx, e->win, d.x0 + e->origin_x, d.y0 +
			e->origin_y, (coord.z * 0x2A00FF) + 0x27FF00);
		if (d.x0 == d.x1 && d.y0 == d.y1)
			break ;
		d.e2 = d.err;
		if (d.e2 > -d.dx)
		{
			d.err -= d.dy;
			d.x0 += d.sx;
		}
		if (d.e2 < d.dy)
		{
			d.err += d.dx;
			d.y0 += d.sy;
		}
	}
}

static void	ft_isometric_convertion(int x, int y, t_env *e)
{
	t_temp		coord;

	coord.x0 = x - y;
	coord.y0 = (x + y) - (int)(e->map[y].tab[x] * e->coef_z);
	if (x + 1 < e->map[y].nb_col)
	{
		coord.x1 = (x + 1) - y;
		coord.y1 = ((x + 1) + y) - (int)(e->map[y].tab[x + 1] * e->coef_z);
		coord.z = e->map[y].tab[x + 1] * e->coef_z;
		ft_draw_line(e, coord);
	}
	if (e->map[y + 1].tab != NULL && x < e->map[y + 1].nb_col)
	{
		coord.x1 = x - (y + 1);
		coord.y1 = (x + (y + 1)) - (int)(e->map[y + 1].tab[x] * e->coef_z);
		coord.z = e->map[y + 1].tab[x] * e->coef_z;
		ft_draw_line(e, coord);
	}
}

void		ft_draw(t_env *e)
{
	int			y;
	int			x;

	y = 0;
	while (e->map[y].tab != NULL)
	{
		x = 0;
		while (x < e->map[y].nb_col)
		{
			ft_isometric_convertion(x, y, e);
			x++;
		}
		y++;
	}
}
