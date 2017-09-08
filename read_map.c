/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:39:53 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/08 03:08:38 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fd_error_check(int fd)
{
	if (fd < 0)
		ft_putstr("Error opening file");
	return ;
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
	int			count;

	tmap.i = 0;
	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmap.j = 0;
		data = ft_strsplit(line, ' ');
		while (data[count])
			count++;
		if (count > tmap.num_cols)
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			exit(fd);
		}
		while (tmap.j < tmap.num_cols)
		{
			tmap.map_arr[tmap.i][tmap.j] = ft_atoi(data[tmap.j]);
			tmap.j++;
		}
		tmap.i++;
		free(line);
	}
}

t_map			store_map(char *filename)
{
	int			fd;
	t_map		tmap;

	fd = open(filename, O_RDONLY);
	fd_error_check(fd);
	get_map_dim(fd, &tmap);
	tmap.map_arr = ft_arr_ints(tmap.num_rows, tmap.num_cols);
	close(fd);
	fd = open(filename, O_RDONLY);
	fd_error_check(fd);
	populate_map(fd, tmap);
	close(fd);
	return (tmap);
}
