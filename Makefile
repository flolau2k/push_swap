# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauer <flauer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 11:55:35 by flauer            #+#    #+#              #
#    Updated: 2023/04/21 14:55:27 by flauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJDIR = obj/
SRCDIR = src/

SRCS = push_swap.c
OBJS = $(SRCS:%.c=%.o)

SRC = $(addprefix $(SRCDIR), $(SRCS))
OBJ = $(addprefix $(OBJDIR), $(OBJS))

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc -o $(NAME) $(OBJ) -Llibft -lft

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

$(LIBFT):
	make -C $(@D)
