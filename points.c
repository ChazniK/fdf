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
#include "libft/libft.h"

int			fd_error_check(int fd)
{
	if (fd < 0)
		ft_putstr("Error opening file");
	return (1);
}
/*static int	count_cols(char *line, int i)
{
	while ()
}*/

static int	count_rows(int fd)
{
	char	*line;
	int		rows;
	int		i;
	int		cols;

	i = 0;
	rows = 0;
	while (get_next_line(fd, &line) == 1)
	{
		rows++;
	}
	cols = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			cols++;
		i++;
	}
	printf("%s\n", line);
	printf("%d\n", cols);
	return (rows);
}

void		read_map()
{
	int		fd;
	int		i;
	int		num_rows;
	int		num_cols;
	
	fd = open("42.txt", O_RDONLY);
	fd_error_check(fd);
	num_rows = 0;
	num_cols = 0;
	i = 0;
	if (fd > 0)
	{
		num_rows = count_rows(fd);
		printf("Rows 	:%d\n", num_rows);
	//	printf("Columns :%d\n", num_rows);
	}
	close(fd);
}

int			main()
{
	read_map();
	return (0);
}
