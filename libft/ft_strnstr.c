/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:18:53 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/22 15:41:21 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;

	i = ft_strlen(little);
	if (i == 0)
		return ((char *)big);
	while (*big && i <= len--)
		if (ft_memcmp(big++, little, i) == 0)
			return ((char *)big - 1);
	return (NULL);
}
