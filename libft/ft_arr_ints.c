/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:14:02 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/07 16:43:40 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_arr_ints(int rows, int cols)
{
	int		i;
	int		j;
	int		**new_arr;

	i = 0;
	new_arr = (int**)malloc(sizeof(int*) * rows);
	if (!new_arr)
		return (NULL);
	while (i < rows)
	{
		new_arr[i] = (int*)malloc(sizeof(int) * cols);
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
