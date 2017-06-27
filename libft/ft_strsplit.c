/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:15:16 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/22 15:41:41 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int				i;
	int				q;
	char			**ret;
	int				p;

	i = 0;
	p = 0;
	q = 0;
	if (!s || !(ret = (char **)malloc(sizeof(char*) * (ft_wordc(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			p = i;
			while (s[i] && s[i] != c)
				i++;
			ret[q++] = ft_strsub(s, p, i - p);
		}
	}
	ret[q] = 0;
	return (ret);
}
