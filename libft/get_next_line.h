/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:23:07 by ckatz             #+#    #+#             */
/*   Updated: 2017/06/22 09:01:52 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define A if(s[fd]&&(u=ft_strstr(s[fd],"\n"))&&((u[0]='\0')||1)
# define B (*line=ft_strdup(s[fd]))&&(t=s[fd])&&(s[fd]=ft_strdup(&u[1])))
# define OUTPUT A && B {free(t?t:0);return 1;}
# define C u=NULL;b[c[0]]='\0';if(s[fd])
# define D free(u);}else s[fd]=ft_strdup(b)
# define INPUT C {u=s[fd];s[fd]=ft_strjoin(s[fd],b); D;
# define E t=s[fd];*line=ft_strdup(s[fd]);free(t);s[fd]=NULL;
# define SPECIAL {E;return 1;}

# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
