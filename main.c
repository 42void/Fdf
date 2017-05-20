/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 14:49:01 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/01/31 19:33:53 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_env	*e;

	if (ac != 2)
	{
		ft_putendl_fd("Argument error", 2);
		exit(EXIT_FAILURE);
	}
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		ft_error();
	e->origin_x = 300;
	e->origin_y = 200;
	e->space = 20;
	e->coef_z = 0.2;
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !av[1])
		ft_error();
	e->map = int_tab(av[1], fd, 0);
	if (!(e->mlx = mlx_init()))
		ft_error();
	e->win = mlx_new_window(e->mlx, S_SCREEN_WIDTH, S_SCREEN_HEIGHT, "42");
	mlx_hook(e->win, 2, 3, ft_key_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
