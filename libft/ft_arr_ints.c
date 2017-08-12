#include "libft.h"

int		**ft_arr_ints(int rows, int cols)
{
	int		i;
	int		**new_arr;
	
	i = 0;
	new_arr = (int**)malloc(sizeof(int*) * rows);
	if (!new_arr)
		return (NULL);
	while (i < cols)
	{
		new_arr[i] = (int*)malloc(sizeof(int) * cols);
		if (!new_arr[i])
			return (NULL);
		ft_bzero(new_arr[i], cols);
		i++;
	}
	return (new_arr);
}
