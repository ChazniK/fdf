/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:39:53 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/07 19:58:59 by ckatz            ###   ########.fr       */
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
	char	**split;
	int		i;
	int		check;

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

static void	populate_map(int fd, t_map tmap)
{
	char	**data;
	char	*line;

	tmap.i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmap.j = 0;
		data = ft_strsplit(line, ' ');
		while (tmap.j < tmap.num_cols)
			tmap.j++;
		if (tmap.j < (tmap.num_cols - 1))
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return ;
		}
		tmap.j = 0;
		while (tmap.j < tmap.num_cols)
		{
			tmap.map_arr[tmap.i][tmap.j] = ft_atoi(data[tmap.j]);
			free(data[tmap.j]);
			tmap.j++;
		}
		tmap.i++;
		free(data);
		free(line);
	}	
}

t_map		store_map(char *filename)
{
	int		fd;
	t_map	tmap;

	fd = open(filename, O_RDONLY);
	fd_error_check(fd);
	get_map_dim(fd, &tmap);
	tmap.map_arr = ft_arr_ints(tmap.num_rows, tmap.num_cols);
	close(fd);
	fd = open(filename, O_RDONLY);
	fd_error_check(fd);
	populate_map(fd, tmap);
	/*tmap.i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmap.j = 0;
		data = ft_strsplit(line, ' ');
		while (tmap.j < tmap.num_cols)
		{
			tmap.map_arr[tmap.i][tmap.j] = ft_atoi(data[tmap.j]);
			free(data[tmap.j]);
			tmap.j++;
		}
		tmap.i++;
		free(data);
		free(line);
	}*/
	int a = 0;
	while (a < tmap.num_rows)
	{
		int b = 0;
		while (b < tmap.num_cols)
		{
			printf("%d ", tmap.map_arr[a][b]);
			b++;
		}
		printf("\n");
		a++;
	}
	close(fd);
	return (tmap);
}

int			main(int argc, char **argv)
{
	char	*filename;
	t_map	map;

	filename = argv[1];
	map = store_map(filename);

//	map = store_map(filename);
	return (argc);
}
