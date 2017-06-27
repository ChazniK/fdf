/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:43:28 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/10 14:54:46 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	size;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	size = (unsigned char)len;
	if (s == d)
		return (dest);
	if (s < d)
	{
		s = (unsigned char*)src + size - 1;
		d = dest + size - 1;
		while (size--)
			*d-- = *s--;
	}
	else
	{
		while (size--)
			*d++ = *s++;
	}
	return (dest);
}
