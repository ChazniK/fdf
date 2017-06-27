/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 09:49:38 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/22 15:40:53 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*new_str;
	int		i;
	int		k;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_strnew(len);
	i = 0;
	if (!new_str || !s1 || !s2)
		return (NULL);
	k = 0;
	while (s1[i] != '\0')
	{
		new_str[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_str[k] = s2[i];
		i++;
		k++;
	}
	return (new_str);
}
