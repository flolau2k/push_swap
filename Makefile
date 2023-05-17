# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauer <flauer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 11:55:35 by flauer            #+#    #+#              #
#    Updated: 2023/05/17 10:45:53 by flauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				push_swap
BONUS_NAME =		checker

CC =				cc
CFLAGS =			-g -Wall -Wextra -Werror

LIBFT =				libft/libft.a

OBJDIR =			obj/
SRCDIR =			src/

SRCS_SORT =			rotation_helper.c chunk_helper.c insertion_helper.c \
					optimizers.c sort.c helper.c
SRCS_INIT =			init.c element.c push.c rev_rot.c rot.c swap.c checks.c \
					presort.c debug.c cleanup.c
SRCS_BONUS =		checker.c
SRCS_MANDATORY =	push_swap.c

OBJS_SORT =			$(SRCS_SORT:%.c=%.o)
OBJS_INIT =			$(SRCS_INIT:%.c=%.o)
OBJS_BONUS =		$(SRCS_BONUS:%.c=%.o)
OBJS_MANDATORY =	$(SRCS_MANDATORY:%.c=%.o)

SRC_SORT =			$(addprefix $(SRCDIR), $(SRCS_SORT))
SRC_STACK =			$(addprefix $(SRCDIR), $(SRCS_INIT))
SRC_BONUS =			$(addprefix $(SRCDIR), $(SRCS_BONUS))
SRC_MANDATORY =		$(addprefix $(SRCDIR), $(SRCS_MANDATORY))

OBJ_MANDATORY =		$(addprefix $(OBJDIR), $(OBJS_MANDATORY))
OBJ_SORT =			$(addprefix $(OBJDIR), $(OBJS_SORT))
OBJ_INIT =			$(addprefix $(OBJDIR), $(OBJS_INIT))
OBJ_BONUS =			$(addprefix $(OBJDIR), $(OBJS_BONUS))

.PHONY =			ft all clean fclean re

all: $(LIBFT) $(NAME) $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJ_MANDATORY) $(OBJ_SORT) $(OBJ_INIT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_MANDATORY) $(OBJ_SORT) $(OBJ_INIT) -Llibft -lft
	@echo "built $(NAME)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C libft clean
	/bin/rm -rf $(OBJDIR)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME) $(BONUS_NAME)

re:	fclean all

$(LIBFT):
	@git submodule update --init --recursive --remote
	@make -C $(@D)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(OBJ_INIT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_INIT) $(OBJ_BONUS) -Llibft -lft
	@echo "built $(BONUS_NAME)"
