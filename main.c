/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:55:02 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/13 16:17:15 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			main(void)
{
	t_map	map;
	t_env	te;

	te.mlx = mlx_init();
	map = store_map();
/*	int	a = 0;
	int	b;
	while (a < map.num_rows)
	{
		b = 0;
		while (b < map.num_cols)
		{
			printf("%d ", map.map_arr[a][b]);
			b++;
		}		
		a++;
		printf("\n");
	}*/
	te.win = mlx_new_window(te.mlx, 640, 480, "fdf");
	cart_to_iso(map, te);
	mlx_loop(te.mlx);
	return (0);
}
