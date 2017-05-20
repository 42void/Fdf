/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 22:57:32 by lkhamsay          #+#    #+#             */
/*   Updated: 2015/01/31 18:53:26 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_validity(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0 && ft_isspace(line[i]) == 0 &&
		line[i] != '-')
		{
			ft_putendl_fd("Invalid map. You shall not pass.", 2);
			exit (EXIT_FAILURE);
		}
		++i;
	}
}

static int	tab_size(int fd)
{
	char	*line;
	int		nb_lines;
	int		ret;

	nb_lines = 0;
	ret = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		nb_lines++;
		free(line);
	}
	if (ret == -1)
		ft_error();
	if (close(fd) == -1)
		ft_error();
	if (nb_lines == 0)
	{
		ft_putendl_fd("Empty file", 2);
		exit(EXIT_FAILURE);
	}
	return (nb_lines);
}

static int	*tab_line(char *line, int *nb_col)
{
	int		*tab;
	char	**tmp;

	if (!(tmp = ft_strsplit(line, ' ')))
		ft_error();
	map_validity(line);
	while (tmp[*nb_col])
		(*nb_col)++;
	if (!(tab = (int *)malloc(sizeof(int) * *nb_col)))
		ft_error();
	*nb_col = 0;
	while (tmp[*nb_col])
	{
		tab[*nb_col] = ft_atoi(tmp[*nb_col]);
		(*nb_col)++;
	}
	return (tab);
}

t_elvis		*int_tab(char *path, int fd, int j)
{
	char	*line;
	int		nb_col;
	t_elvis	*tab_struct;
	int		ret;

	if (!(tab_struct = (t_elvis *)malloc(sizeof(t_elvis) * (tab_size(fd) + 1))))
		ft_error();
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error();
	ret = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		nb_col = 0;
		tab_struct[j].tab = tab_line(line, &nb_col);
		free(line);
		tab_struct[j].nb_col = nb_col;
		j++;
	}
	if (ret == -1)
		ft_error();
	if (close(fd) == -1)
		ft_error();
	tab_struct[j].tab = NULL;
	tab_struct[j].nb_col = 0;
	return (tab_struct);
}
