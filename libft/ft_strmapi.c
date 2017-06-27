/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:20:29 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/09 17:05:46 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	size_t	size;
	char	*str;

	if (s)
	{
		size = (size_t)(ft_strlen(s));
		str = ft_strnew(size);
		index = 0;
		if (!str)
			return (NULL);
		else
		{
			while (s[index])
			{
				str[index] = (f)(index, s[index]);
				index++;
			}
			return (str);
		}
	}
	return (NULL);
}
