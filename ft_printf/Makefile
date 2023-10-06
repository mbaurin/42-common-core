# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 07:36:08 by mbaurin           #+#    #+#              #
#    Updated: 2021/02/25 07:36:10 by mbaurin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =	src/ft_printf.c \
		src/ft_printf_utils.c \
		src/ft_handle_memory.c \
		src/ft_initialisation.c \
		src/ft_handle_char.c \
		src/ft_handle_unsigned_int.c \
		src/ft_handle_hexa_unsigned.c \
		src/ft_handle_pointer.c \
		src/ft_handle_string.c \
		src/ft_handle_signed_int.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -I.

%.o%.c:
	gcc $(CFLAGS) -c $< -o

all : $(NAME)

$(OBJS) : includes/ft_printf.h libft/includes/libft.h

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean :
	$(MAKE) clean -C ./libft 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY: all, clean, flcean, re
