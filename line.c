/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 12:50:34 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/11 17:01:04 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

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

	line.dx = line.dx/line.step;
	line.dy = line.dy/line.step;

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

int		main(void)
{
	float	x;
	float	y;
	int		i;
	t_line	line;
	t_env	env;

	line.x1 = 5;
	line.y1 = 5;
	line.x2 = 20;
	line.y2 = 200;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 640, 400, "line");	
	dda(line, env);
	mlx_loop(env.mlx);
}
