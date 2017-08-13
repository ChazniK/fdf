/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:46:36 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/13 18:21:31 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*static void	dda(t_line line, t_env env)
{
	float	x;
	float	y;
	int		i;

	line.dx = fabsf(line.x2 - line.x1);
	line.dy = fabsf(line.y2 - line.y1);
	if (line.dx >= line.dy)
		line.step = line.dx;
	else
		line.step = line.dy;
	line.dx = line.dx / line.step;
	line.dy = line.dy / line.step;
	x = line.x1;
	y = line.y1;
	i = 1;
	while (i <= line.step)
	{
		mlx_pixel_put(env.mlx, env.win, x, y, 0X0000FF00);
		x = x + line.dx;
		y = y + line.dy;
		i = i + 1;
	}
}*/

void		cart_to_iso(t_map tmap, t_env te)
{
	int		x;
	int		y;
	int		x1;

	//te.tp.cart_x = 0;
	//te.tp.cart_y = 0;
	te.tp.iso_x = 0;
	te.tp.iso_y = 0;
	x1 = 0;
	x = 0;
	while (x  < tmap.num_rows)
	{
		y = 0;
		while (y < tmap.num_cols)
		{
			printf("%d ", tmap.map_arr[x][y]);
			x1 = x;
			if (tmap.map_arr[x][y] > 0)
			{
				x1 = x1 - tmap.map_arr[x][y];
			}
			//te.tp.cart_x = (x * 15 + 400) / 2;
			//te.tp.cart_y = (y1 * 15 + 20) / 2;
			te.tp.iso_y = (y + x1) / 2; 
			te.tp.iso_x = (y - x1);
			mlx_pixel_put(te.mlx, te.win, te.tp.iso_x * 15 + 200, te.tp.iso_y * 15 + 200, 0X0000FF00);
			y++;
		}
		printf("\n");
		x++;
	}
}
