/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:28:14 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/22 15:40:19 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		len;
	char	check;

	i = 0;
	len = 0;
	check = (char)c;
	while (str[i] != '\0')
	{
		if (str[len] != check)
		{
			len++;
		}
		i++;
	}
	if (i == len && str[len] != check)
		return (0);
	else
		return (char*)((str) + len);
}
