/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:50:26 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/11 17:21:23 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*conv_dest;
	unsigned char	*conv_src;

	i = 0;
	conv_dest = (unsigned char*)dest;
	conv_src = (unsigned char*)src;
	while (i < n)
	{
		conv_dest[i] = conv_src[i];
		i++;
	}
	return (conv_dest);
}
