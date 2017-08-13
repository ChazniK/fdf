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

int			main(void)
{
	t_map	map;
	t_env	te;

	te.mlx = mlx_init();
	map = store_map();
	te.win = mlx_new_window(te.mlx, 640, 480, "fdf");
	put_points(map, te);
	mlx_loop(te.mlx);
	return (0);
}
