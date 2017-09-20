/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:46:36 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/20 18:15:56 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		swap(int *n1, int *n2)
{
	int			temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

static void		abs_swap(int **a, int **b, t_line *co_xy)
{
	if (abs(co_xy->x1 - co_xy->x2) >= abs(co_xy->y1 - co_xy->y2))
	{
		*a = &co_xy->x1;
		*b = &co_xy->y1;
	}
	else
	{
		swap(&co_xy->x1, &co_xy->y1);
		swap(&co_xy->x2, &co_xy->y2);
		*a = &co_xy->y1;
		*b = &co_xy->x1;
	}
}

static void		draw_line(t_env m_l_x, t_line co_xy)
{
	double		slope;
	double		offset;
	int			iterate;
	int			*a;
	int			*b;

	slope = 0;
	offset = 0;
	abs_swap(&a, &b, &co_xy);
	iterate = -1 + (2 * (co_xy.x1 < co_xy.x2));
	slope = ((double)abs(co_xy.y1 - co_xy.y2) /
			(double)abs(co_xy.x1 - co_xy.x2)) *
		(-1 + (2 * (co_xy.y1 < co_xy.y2)));
	while (co_xy.x1 != co_xy.x2)
	{
		if (offset >= 0.49999 || offset <= -0.5)
		{
			offset -= -1 + (2 * (co_xy.y1 < co_xy.y2));
			co_xy.y1 += -1 + (2 * (co_xy.y1 < co_xy.y2));
		}
		mlx_pixel_put(m_l_x.mlx, m_l_x.win, *a, *b, 0X0000FF00);
		co_xy.x1 += iterate;
		offset += slope;
	}
}

void			draw_horizontal(t_map tmap, t_env te)
{
	int			x;
	int			y;
	t_line		line;

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
			draw_line(te, line);
			x++;
		}
		y++;
	}
}

void			draw_vertical(t_map tmap, t_env te)
{
	int			x;
	int			y;
	t_line		line;

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
			draw_line(te, line);
			y++;
		}
		x++;
	}
}
