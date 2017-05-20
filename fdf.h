/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 18:16:01 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/01/31 21:10:49 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <mlx.h>
# include "libft.h"
# include <math.h>

# define S_SCREEN_WIDTH 800
# define S_SCREEN_HEIGHT 800

typedef struct		s_elvis
{
	int				*tab;
	int				nb_col;
}					t_elvis;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_elvis			*map;
	int				space;
	int				origin_x;
	int				origin_y;
	float			coef_z;
}					t_env;

typedef struct		s_temp
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				z;
}					t_temp;

typedef struct		s_var_draw
{
	int				dx;
	int				sx;
	int				dy;
	int				err;
	int				sy;
	int				e2;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_var_draw;

t_elvis				*int_tab(char *path, int fd, int j);
int					ft_key_hook(int keycode, t_env *e);
int					ft_expose_hook(t_env *e);
void				ft_draw(t_env *e);
void				ft_error(void);

#endif
