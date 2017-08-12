/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 17:39:25 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/11 18:46:51 by ckatz            ###   ########.fr       */
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

	i = 0;
	tmap->num_rows = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmap->num_rows++;
	}
	tmap->num_cols = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			tmap->num_cols++;
		i++;
	}
	free(line);
}

void		store_map()
{
	int		fd;
	int		**map_arr;
	char	*line;
	t_map	tmap;
	//int		i;
	
	fd = open("42.fdf", O_RDONLY);
	fd_error_check(fd);
	if (fd > 0)
	{
		get_map_dim(fd, &tmap);
		printf("point 1\n");
		map_arr = ft_arr_ints(tmap.num_rows, tmap.num_cols);
		printf("point 2\n");
		if (get_next_line(fd, &line) == 1)	
		{
			//i = 0;
			printf("point 3\n");
			//tmap.data = ft_strsplit(line, ' ');
			//printf("%s\n", tmap.data);
			//printf("%s\n", tmap.data[0]);
		}
 		/*int	a = 0;
		int	b;
		while (a < tmap.num_rows)
		{
			b = 0;
			while (b < tmap.num_cols)
			{
				printf("%d", map_arr[a][b]);
				b++;
			}
			printf("\n");
			a++;
		}
		printf("Rows 	:%d\n", tmap.num_rows);
		printf("Columns :%d\n", tmap.num_cols);*/
	}
	close(fd);
}

int			main()
{
	store_map();
	return (0);
}
