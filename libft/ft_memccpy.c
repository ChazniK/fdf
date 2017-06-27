/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:40:39 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/11 17:21:13 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*conv_dest;
	unsigned char	*conv_src;

	conv_dest = (unsigned char*)dest;
	conv_src = (unsigned char*)src;
	while (n > 0)
	{
		if (*conv_src == ((unsigned char)c))
		{
			*conv_dest++ = *conv_src;
			return (conv_dest);
		}
		else
			*conv_dest++ = *conv_src++;
		n--;
	}
	return (NULL);
}
