/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:39:53 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/16 18:11:24 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	fd_error_check(int fd)
{
	if (fd < 0)
		ft_putstr("Error opening file");
	return ;
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
	}
	tmap->num_cols = 0;
	while (copy[i])
	{
		if (ft_isdigit(copy[i]))
			tmap->num_cols++;
		i++;
	}
}

t_map		store_map(void)
{
	int		fd;
	char	*line;
	char	**data;
	t_map	tmap;

	fd = open("42.fdf", O_RDONLY);
	fd_error_check(fd);
	get_map_dim(fd, &tmap);
	tmap.map_arr = ft_arr_ints(tmap.num_rows, tmap.num_cols);
	close(fd);
	fd = open("42.fdf", O_RDONLY);
	fd_error_check(fd);
	tmap.i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmap.j = -1;
		data = ft_strsplit(line, ' ');
		while (++tmap.j < tmap.num_cols)
			tmap.map_arr[tmap.i][tmap.j] = ft_atoi(data[tmap.j]);
		tmap.i++;
	}
	close(fd);
	return (tmap);
}
