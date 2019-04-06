# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 22:26:26 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/04/04 13:11:43 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#FLAGS = -Wall -Wextra -Werror

FLAGS =

LIBFT = -L libft/ -lft

MINILIB = -L minilibx_macos/ -lmlx

FRAMEW = -framework OpenGL -framework Appkit

CFILES = main.c primitives.c draw.c reader.c get_next_line.c \
		 screen.c convert.c

OBJ = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) fdf.h
	make -C libft
	make -C minilibx_macos
	gcc $(FLAGS) $(OBJ) -o $(NAME) -Iminilibx_macos $(LIBFT) $(MINILIB) $(FRAMEW)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(CFILES) -Ilibft -Iminilibx_macos

clean:
	make clean -C libft
	make clean -C minilibx_macos
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all