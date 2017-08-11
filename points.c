/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 17:39:25 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/11 17:41:16 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"

int void	fd_error_check(int fd)
{
	if (fd < 0)
	{
		ft_putstr("Error opening file");
		return (1);
	}
}

static int	read_cols(int fd)
{
	char	*lines;
	int		rows;

	rows = 0;
	while (get_next_line(fd, &lines) == 1)
	{
		rows++;
	}
	return (rows);
}

void		read_map()
{
	char	*lines;
	char	**holder;
	int		fd;
	int		i;
	int		num_rows;
	
	fd = open("42.txt", O_RDONLY);
	fd_error_check(fd);
	num_rows = 0;
	i = 0;
	if (fd > 0)
	{

	}
	close(fd);
}

int			main()
{
	return (0);
}
