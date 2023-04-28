# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 11:55:35 by flauer            #+#    #+#              #
#    Updated: 2023/04/28 13:37:02 by flauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -mcmodel=large

LIBFT_DIR = libft

OBJDIR = obj/
SRCDIR = src/

SRCS = push_swap.c helper.c swap.c push_rot.c rev_rot.c
OBJS = $(SRCS:%.c=%.o)

SRC = $(addprefix $(SRCDIR), $(SRCS))
OBJ = $(addprefix $(OBJDIR), $(OBJS))

.PHONY = ft all clean fclean re 

all: ft $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -Llibft -lft
	@echo "built $(NAME)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFT_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	/bin/rm -rf $(NAME)

re:	fclean all

ft:
	@make -C $(LIBFT_DIR)
