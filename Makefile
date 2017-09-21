# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 14:51:42 by omeyer            #+#    #+#              #
#    Updated: 2017/09/21 12:16:36 by ckatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = read_map.c draw.c main.c

OBJ = read_map.o draw.o main.o

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

FETCHLIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft/ all
	@gcc -o $(NAME) $(SRC) $(FLAGS) $(FETCHLIB)

clean:
	@$(MAKE) -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C libft/ fclean

re:	fclean all
