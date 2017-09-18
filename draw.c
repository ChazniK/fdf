/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:46:36 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/18 18:55:26 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	dda(t_line line, t_env env)
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
}

void		cart_to_iso(t_map tmap, t_env te, t_co_pts *pts)
{
	int		x;
	int		y;
	t_line	line;
	float	scale;
	int		i;

	pts = (t_co_pts*)malloc(sizeof(*pts) * (tmap.num_rows * tmap.num_cols));
	te.tp.cart_x = 0;
	te.tp.cart_y = 0;
	te.tp.iso_x = 0;
	te.tp.iso_y = 0;
	line.points_x = ft_arr_doubles(tmap.num_rows, tmap.num_cols);
	line.points_y = ft_arr_doubles(tmap.num_rows, tmap.num_cols);
	y = 0;
	scale = 15;
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
			line.points_x[y][x] = te.tp.iso_x;
			line.points_y[y][x] = te.tp.iso_y;
			//mlx_pixel_put(te.mlx, te.win, te.tp.iso_x, te.tp.iso_y, 0X00FF0000);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < tmap.num_rows)
	{
		x = 0;
		while (x < (tmap.num_cols - 1))
		{
			line.x1 = line.points_x[y][x];
			line.y1 = line.points_y[y][x];
			line.x2 = line.points_x[y][x + 1];
			line.y2 = line.points_y[y][x + 1];
			dda(line, te);
			printf("%f ", line.points_x[y][x]);
			if (tmap.map_arr[y][x] > 0)
				mlx_pixel_put(te.mlx, te.win, line.points_x[y][x], line.points_y[y][x], 0X00FF0000);
			else
				mlx_pixel_put(te.mlx, te.win, te.tp.iso_x, te.tp.iso_y, 0X00FFFF00);
			x++;
		}
		printf("\n");
		y++;
	}

	x = 0;
	while (x < tmap.num_cols)
	{
		y = 0;
		while (y < (tmap.num_rows - 1))
		{
			line.x1 = line.points_x[y][x];
			line.y1 = line.points_y[y][x];
			line.x2 = line.points_x[y + 1][x];
			line.y2 = line.points_y[y + 1][x];
			dda(line, te);
			if (tmap.map_arr[y][x] > 0)
				mlx_pixel_put(te.mlx, te.win, te.tp.iso_x, te.tp.iso_y, 0X00FF0000);
			else
				mlx_pixel_put(te.mlx, te.win, te.tp.iso_x, te.tp.iso_y, 0X00FFFF00);
			y++;
		}
		x++;
	}
}
