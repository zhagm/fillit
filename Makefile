# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:58:27 by zmagauin          #+#    #+#              #
#    Updated: 2016/09/25 19:32:38 by zmagauin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the compiler: gcc for C program, define as g++ for C++

# NAME	:=	fillit
# CC		:=	gcc
# CFLAGS  :=	-Wall -Werror -Wextra
# SRC_DIR	:=	./src
# OBJ_DIR	:=	./obj
# INCL	:=	-I./includes
# FILES	:=	fillit_backtrack.c \
# 			fillit_board.c \
# 			fillit_struct_logic.c \
# 			fillit_trim \
# 			fillit_validate.c
# OBJS	:= 	$(addprefix $(OBJ_DIR)/,$(FILES:%.c=%.o))

# LIB		:=	./libft

# all:
# 	mkdir -p $(OBJ_DIR)
# 	@$(MAKE) $(NAME)

# $(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) $(INCL) -I ./libft/libft.a -I ./libft/includes -o $@ -c $<

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(INCL) -L $(LIB) -l ft -o $(NAME)
# 	# $(CC) main.c $(INCL) $(LIB) $(SRC_DIR)/$(FILES) -o $(NAME)
# 	# gcc main.c -Iincludes libft/libft.a src/fillit_*.c

# # NAME		= fillit
# # INCLUDES	= -Iincludes -Ilibft/includes
# # CFLAGS		= -Wall -Werror -Wextra main.c libft/libft.a
# # LIB			= -Llibft
# # FILES		= $(shell ls src | grep -E "*\.c")
# # # OBJ			= $(FILES:%.c=%.o)

# # all: $(NAME)

# # $(NAME): 
# # 	@gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(FILES)
# # # 	@ar rcs $(NAME) $(OBJ)

# # # $(OBJ): $(FILES)

# # clean:
# # 	@rm -f $(OBJ)

# # fclean: clean
# # 	@rm -f $(NAME)

# # re: fclean all

# # .PHONY: clean fclean all re

NAME		= fillit
SRC_DIR		= src
CFLAGS		= -Wall -Werror -Wextra -Iincludes -c
FILES		= $(shell ls | grep -E "ft_.+\.c")
OBJ			= $(FILES: $(SRC_DIR)/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	@gcc main.c $(CFLAGS) $(FILES)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
