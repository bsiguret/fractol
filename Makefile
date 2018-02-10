# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 04:36:14 by bsiguret          #+#    #+#              #
#    Updated: 2018/02/10 02:29:52 by bsiguret         ###   ########.fr        #
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
FLAGS			=	-Wall -Werror -Wextra -g
INC				=	-I./includes/ -I./libft/ -I /usr/X11/include
LIB				=  -L /usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit -Llibft -lft

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
