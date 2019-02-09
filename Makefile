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

NAME		= fillit
# CFLAGS	= -Wall -Werror -Wextra -Iincludes -c
CFLAGS	= -Wall -Werror -Wextra main.c libft/libft.a 
FILES		= $(shell ls | grep -E "fillit_.+\.c")
# OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): 
	@gcc $(CFLAGS) -o $(NAME) $(FILES)
# 	@ar rcs $(NAME) $(OBJ)

# $(OBJ): $(FILES)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
