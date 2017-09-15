/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_doubles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 18:29:04 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/13 18:32:34 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		**ft_arr_doubles(int rows, int cols)
{
	int		i;
	int		j;
	double	**new_arr;

	i = 0;
	new_arr = (double**)malloc(sizeof(double*) * rows);
	if (!new_arr)
		return (NULL);
	while (i < rows)
	{
		new_arr[i] = (double*)malloc(sizeof(double) * cols);
		if (!new_arr[i])
			return (NULL);
		j = 0;
		while (j < cols)
		{
			new_arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new_arr);
}
