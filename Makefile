# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 22:26:26 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/09/01 18:47:30 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -O2 -Wall -Wextra -Werror

LIBFT = -L libft/ -lft

MINILIB = -L minilibx_macos/ -lmlx

FRAMEW = -framework OpenGL -framework Appkit

CFILES = main.c dot.c draw.c reader.c get_next_line.c image.c exit_msgs.c \
		 screen.c zoom_shift.c change_dots.c keyboard.c mouse.c \
		 menu.c transparent.c box.c draw_box.c colorize.c color.c rotation.c

OBJ = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) fdf.h config.h
	make -C libft
	make -C minilibx_macos
	gcc $(FLAGS) $(OBJ) -o $(NAME) -Iminilibx_macos $(LIBFT) $(MINILIB) $(FRAMEW)

$(OBJ): $(CFILES) fdf.h config.h
	gcc $(FLAGS) -c $(CFILES) -Ilibft -Iminilibx_macos

clean:
	make clean -C libft
	make clean -C minilibx_macos
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
