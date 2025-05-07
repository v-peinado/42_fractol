# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:20:29 by vpeinado          #+#    #+#              #
#    Updated: 2025/05/07 11:08:27 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	= fractol

#Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

#Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

#Includes
INC			=	-I ./includes/\
				-I ./minilibx-linux/

#Sources
SRC_PATH	=	src/
SRC			= main.c mandelbrot.c utils.c utils2.c help.c  \
				burning_ship.c julia.c checks.c hooks.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

#Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -L ${MLX_PATH} -lmlx -lXext -lX11 -lm -lbsd
	@echo "\033[32mFract-ol: OK!"

clean:
	@echo "\033[33mObjet files: \033[31mDeleted!"
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@echo "\033[33mFract-ol: \033[31mDeleted!"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean