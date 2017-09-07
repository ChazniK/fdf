/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 08:38:26 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/07 08:56:27 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			read_map(t_map *map, int fd, char *filename)
{
	int		i;
	char	*line;

	map->num_rows = 0;
	map->num_cols = 0;
	fd = open(filename, O_RDONLY);
	while ((get_next_line(fd, &line) == 1))
	{
		while (line[i])
		{

		}
	}
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*filename;

	filename = argv[1];

	return (argc);
}
