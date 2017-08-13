/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:46:36 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/13 16:17:12 by ckatz            ###   ########.fr       */
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

void		put_points(t_map tmap, t_env te)
{
	int		x;
	int		y;

	x = 0;
	while (x  < tmap.num_cols)
	{
		y = 0;
		while (y < tmap.num_rows)
		{
			mlx_pixel_put(te.mlx, te.win, x * 20 + 130, y * 20 + 130, 0X0000FF00);
			y++;
		}
		x++;
	}
}
