/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:39:53 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/20 18:12:04 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fd_error_check(int fd)
{
	if (fd < 0)
		perror("Error opening file");
	return (fd);
}

static void		get_map_dim(int fd, t_map *tmap)
{
	char		*line;
	char		**split;
	int			i;
	int			check;

	tmap->num_rows = 0;
	tmap->num_cols = 0;
	i = 0;
	check = 0;
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ');
		if (check == 0)
		{
			while (split[i])
			{
				tmap->num_cols++;
				i++;
				check++;
			}
		}
		tmap->num_rows++;
		free(line);
	}
}

/*
** Stores map based on obtained dimensions
** Does relevent error checking for maps with differing line lengths
*/

static void		populate_map(int fd, t_map tmap)
{
	char		**data;
	char		*line;
	int			cols;
	int			index;

	index = 0;
	while (get_next_line(fd, &line) == 1)
	{
		cols = 0;
		data = ft_strsplit(line, ' ');
		while (data[cols])
			cols++;
		if (cols < tmap.num_cols)
		{
			ft_putendl("Found wrong line length. Exiting...");
			exit(fd);
		}
		cols = -1;
		while (++cols < tmap.num_cols)
			tmap.map_arr[index][cols] = ft_atoi(data[cols]);
		index++;
		free(line);
	}
}

t_map			store_map(char *filename)
{
	int			fd;
	t_map		tmap;

	fd = open(filename, O_RDONLY);
	if (fd_error_check(fd) < 0)
		exit(fd);
	get_map_dim(fd, &tmap);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd_error_check(fd) < 0)
		exit(fd);
	tmap.map_arr = ft_arr_ints(tmap.num_rows, tmap.num_cols);
	populate_map(fd, tmap);
	close(fd);
	return (tmap);
}

void			cart_to_iso(t_map tmap, t_env te)
{
	int			x;
	int			y;
	t_line		line;

	line.points_x = ft_arr_doubles(tmap.num_rows, tmap.num_cols);
	line.points_y = ft_arr_doubles(tmap.num_rows, tmap.num_cols);
	y = -1;
	while (++y < tmap.num_rows)
	{
		x = -1;
		while (++x < tmap.num_cols)
		{
			te.tp.cart_x = x * SCALE + 350;
			te.tp.cart_y = y * SCALE + 100;
			te.tp.iso_x = te.tp.cart_x - te.tp.cart_y;
			te.tp.iso_y = (te.tp.cart_x + te.tp.cart_y) / 2;
			if (tmap.map_arr[y][x] > 0)
				te.tp.iso_y = te.tp.iso_y - tmap.map_arr[y][x] * 10;
			line.points_x[y][x] = te.tp.iso_x;
			line.points_y[y][x] = te.tp.iso_y;
		}
	}
}
