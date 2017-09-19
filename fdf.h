/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:32:47 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/19 18:51:04 by ckatz            ###   ########.fr       */
/*   Updated: 2017/09/10 01:41:15 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 640
# define HEIGHT 480
# define ESC 53

typedef struct	s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
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

typedef struct	s_coordinates
{
	int			co_x;
	int			co_y;
}				t_co_pts;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_points	tp;
	t_line		tl;
}				t_env;

t_map			store_map(char *filename);
void			cart_to_iso(t_map tmap, t_env te, t_co_pts *pts);

#endif
