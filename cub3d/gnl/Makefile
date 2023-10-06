# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 14:54:13 by mbaurin           #+#    #+#              #
#    Updated: 2020/12/02 10:47:20 by mbaurin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = src/get_next_line_utils.c \
	 src/get_next_line.c \
	 src/get_next_line_bonus.c \
	 src/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I.

%.o: %.c
	gcc -D BUFFER_SIZE=32 $(CFLAGS) -c $< -o $@

all: $(NAME)

$(OBJS) : includes/get_next_line.h includes/get_next_line_bonus.h

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, flcean, re
