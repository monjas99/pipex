# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 10:00:52 by dmonjas-          #+#    #+#              #
#    Updated: 2023/05/31 12:14:39 by dmonjas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
RM = rm -rf
CC = gcc
CFLAGS = -Wextra -Wall -Werror #-g3 -fsanitize=address

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
LIB_INC = ./libft/inc/
INC_DIR = ./inc/

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_FILES = 
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCLUDE = -I$(INC_DIR) -I$(LIB_INC)

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INLUDE) $(LIBFT) -o $(NAME)
	@echo "Pipex correcto"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(NAME)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "Pipex borrado"
re: fclean all
.PHONY: all re clean fclean
