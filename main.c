/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:55:02 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/08 03:29:43 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_map	map;
	t_env	te;
	char	*filename;

	te.mlx = mlx_init();
	if (argc != 2)
		ft_putendl("Incorrect number of parameters entered!");
	else
	{
		filename = argv[1];
		map = store_map(filename);
		int a = 0;
		while (a < map.num_cols)
		{
			int b = 0;
			while (b < map.num_rows)
			{
				printf("%d ", map.map_arr[a][b]);
				b++;
			}
			printf("\n");
			a++;
		}
		te.win = mlx_new_window(te.mlx, 640, 480, "fdf");
		cart_to_iso(map, te);
		mlx_loop(te.mlx);
	}
	return (0);
}
