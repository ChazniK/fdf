/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:32:47 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/08 03:29:54 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_line
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		dx;
	float		dy;
	float		step;
	int			**points;
}				t_line;

typedef struct	s_map
{
	int			num_rows;
	int			num_cols;
	int			i;
	int			j;
	int			**map_arr;
}				t_map;

typedef struct	s_points
{
	int			iso_x;
	int			iso_y;
	int			cart_x;
	int			cart_y;
}				t_points;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_points	tp;
}				t_env;

t_map			store_map(char *filename);
void			cart_to_iso(t_map tmap, t_env te);

#endif
