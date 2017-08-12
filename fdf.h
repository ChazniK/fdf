/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:32:47 by ckatz             #+#    #+#             */
/*   Updated: 2017/08/11 17:01:01 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include <mlx.h>
#include <math.h> 

typedef struct	s_line
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		dx;
	float		dy;	
	float		step;
}				t_line;

typedef struct	s_map
{
	int			num_rows;
	int			num_cols;
	int			**map;
	char		**data;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

#endif

