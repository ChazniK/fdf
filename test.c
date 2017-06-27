/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:02:30 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/27 13:54:17 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (x < 150)
	{

		x = 10;
		while (y < 150)
		{
			mlx_pixel_put(mlx, win, (x + y), y, 0x00FFFFF);
			mlx_pixel_put(mlx, win, x, (y + x), 0x00FFFFF);
			x += 10;
		}
		y += 10;
	}
	mlx_loop(mlx);
}
