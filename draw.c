/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:46:36 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/15 22:46:50 by ckatz            ###   ########.fr       */
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

	te.tp.cart_x = 0;
	te.tp.cart_y = 0;
	te.tp.iso_x = 0;
	te.tp.iso_y = 0;
	y = 0;
	while (y < tmap.num_rows)
	{
		x = 0;
		while (x < tmap.num_cols)
		{
			te.tp.cart_x = x * 15 + 350;
			te.tp.cart_y = y * 15 + 100;
			te.tp.iso_x = te.tp.cart_x - te.tp.cart_y;
			te.tp.iso_y = (te.tp.cart_x + te.tp.cart_y) / 2;
			if (tmap.map_arr[y][x] > 0)
				te.tp.iso_y = te.tp.iso_y - tmap.map_arr[y][x] * 10;
			mlx_pixel_put(te.mlx, te.win, te.tp.iso_x, te.tp.iso_y, 0X00FF0000);
			x++;
		}
		y++;
	}
}
