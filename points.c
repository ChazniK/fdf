/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 17:39:25 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/12 18:00:42 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "fdf.h"

int			fd_error_check(int fd)
{
	if (fd < 0)
		ft_putstr("Error opening file");
	return (1);
}

static void	get_map_dim(int fd, t_map *tmap)
{
	char	*line;
	int		i;
	char	*copy;

	i = 0;
	tmap->num_rows = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmap->num_rows++;
		copy = ft_strdup(line);
		free(line);
	}
	tmap->num_cols = 0;
	while (copy[i])
	{
		if (ft_isdigit(copy[i]))
			tmap->num_cols++;
		i++;	
	}
	free(copy);
}

void		store_map()
{
	int		fd;
	int		**map_arr;
	char	*line;
	t_map	tmap;

	fd = open("42.fdf", O_RDONLY);
	fd_error_check(fd);
	if (fd > 0)
		get_map_dim(fd, &tmap);
	map_arr = ft_arr_ints(tmap.num_rows, tmap.num_cols);
	close(fd);
	fd = open("42.fdf", O_RDONLY);
	fd_error_check(fd);
	if (fd > 0)
	{
		tmap.i = 0;
		while (get_next_line(fd, &line) == 1)
		{
			tmap.j = 0;
			tmap.data = ft_strsplit(line, ' ');
			free(line);
			while (tmap.j < tmap.num_cols)
			{
				map_arr[tmap.i][tmap.j] = ft_atoi(tmap.data[tmap.j]);
				tmap.j++;
			}
			tmap.i++;
		}
	}
	close(fd);
}

int			main()
{
	store_map();
	return (0);
}
