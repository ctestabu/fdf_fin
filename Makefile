# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 14:44:36 by lgeorgia          #+#    #+#              #
#    Updated: 2019/04/10 15:21:38 by lgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRCS=main.c coordinate.c lists.c draw.c iterline.c free.c mouse.c pixel.c norm.c
OBJECTS=main.o coordinate.o lists.o draw.o iterline.o free.o mouse.o pixel.o norm.o
FLAG=-Wall -Wextra -Werror
all:$(NAME)
$(NAME):
	make -C libft
	gcc -o $(NAME) $(FLAG) $(SRCS) -Llibft -lft -L /Users/lgeorgia/fdf/lib -lmlx -framework OpenGL -framework AppKit

clean:
	/bin/rm -f *.o
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
	make -C libft re
