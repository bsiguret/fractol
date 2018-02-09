# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 04:36:14 by bsiguret          #+#    #+#              #
#    Updated: 2018/02/09 16:50:26 by bsiguret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol
SRCS_NAME		=	main.c\
					paraminit.c\
					paraminit2.c\
					tools.c\
					mandelbrot.c\
					hook.c\
					compfunc.c\
					color.c\
					color2.c\
					colorgradient.c

SRCS_PATH		=	srcs/
SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=	$(SRCS_NAME:.c=.o)
OBJ_PATH		=	obj/
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS			=	-Wall -Werror -Wextra -g
INC				=	-I./includes/ -I./libft/ -I./minilibx_macos/
LIB				=  -I libmlx.a -lmlx -framework OpenGL -framework AppKit -Llibft -lft

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
