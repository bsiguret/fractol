# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 04:36:14 by bsiguret          #+#    #+#              #
#    Updated: 2018/02/16 17:30:04 by bsiguret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol
SRCS_NAME		=	main.c\
					paraminit.c\
					paraminit2.c\
					image.c\
					tools.c\
					tools2.c\
					tools3.c\
					mandelbrot.c\
					julia.c\
					burningship.c\
					glynn.c\
					mandeldrop.c\
					mandelheart.c\
					hook.c\
					compfunc.c\
					compfunc2.c\
					posdata.c\
					color.c\
					color2.c\
					smoothcolor.c\
					thread.c

SRCS_PATH		=	srcs/
SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=	$(SRCS_NAME:.c=.o)
OBJ_PATH		=	obj/
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS			=	-Wall -Werror -Wextra -Ofast
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
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
