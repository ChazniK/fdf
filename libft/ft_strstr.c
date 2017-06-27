/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:16:02 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/22 15:16:14 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	len = ft_strlen(little);
	tmp = (char *)big;
	if (!little[0])
		return ((char *)big);
	while (tmp[i])
	{
		if (tmp[i] == little[0])
		{
			if (ft_strnequ(&tmp[i], (char*)little, len) == 1)
			{
				return (&tmp[i]);
			}
		}
		i++;
	}
	return (NULL);
}
