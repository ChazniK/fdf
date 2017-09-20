/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:08:30 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/20 18:10:12 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

# define SCALE 3
# define WIDTH 800
# define HEIGHT 600
# define ESC 53

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	double		dx;
	double		dy;
	double		step;
	double		**points_x;
	double		**points_y;
}				t_line;

typedef struct	s_map
{
	int			num_rows;
	int			num_cols;
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
	t_line		tl;
}				t_env;

t_map			store_map(char *filename);
void			cart_to_iso(t_map tmap, t_env te);
void			draw_horizontal(t_map tmap, t_env te);
void			draw_vertical(t_map tmap, t_env te);

#endif
