/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:38:42 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/22 15:38:47 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	long	l;
	size_t	cnt;
	char	*str;
	char	neg;

	l = n;
	neg = (l < 0 ? 1 : 0);
	cnt = ft_charcount(l);
	str = ft_strnew(cnt + neg);
	if (str == NULL)
		return (NULL);
	if (neg)
	{
		l = -l;
		str[0] = '-';
	}
	while (cnt > 0)
	{
		str[cnt + neg - 1] = (l % 10) + '0';
		cnt--;
		l /= 10;
	}
	return (str);
}
