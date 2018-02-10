# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 04:36:14 by bsiguret          #+#    #+#              #
#    Updated: 2018/02/10 15:46:35 by bsiguret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol
SRCS_NAME		=	main.c\
					paraminit.c\
					paraminit2.c\
					image.c\
					tools.c\
					mandelbrot.c\
					hook.c\
					compfunc.c\
					posdata.c\
					color.c\
					color2.c\
					colorgradient.c\
					thread.c

SRCS_PATH		=	srcs/
SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=	$(SRCS_NAME:.c=.o)
OBJ_PATH		=	obj/
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS			=	-Wall -Werror -Wextra -g -Ofast
INC				=	-I./includes/ -I./libft/ -I./minilibx_macos
LIB				=	-framework OpenGL -framework AppKit libft/libft.a
MLX				=	minilibx_macos/libmlx.a

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB) $(MLX)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
