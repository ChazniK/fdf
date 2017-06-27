/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:34:50 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/11 16:03:11 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	size;
	int		i;

	if (s)
	{
		size = (size_t)(ft_strlen(s));
		str = ft_strnew(size);
		if (!str)
			return (NULL);
		else
		{
			i = 0;
			while (s[i])
			{
				str[i] = f(s[i]);
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
