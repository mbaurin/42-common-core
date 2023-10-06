NAME = push_swap

SRCS = src/main.c \
        	src/get_stack_a.c \
			src/sort_small.c \
			src/sort_quarters.c \
			src/move_quarters1.c \
			src/move_quarters2.c \
			src/push.c \
			src/rotate.c \
			src/swap.c \
			src/moves.c \
			src/init.c \
			src/find_big_small.c \
			src/stack_operations.c \
			src/median.c \
			src/utils1.c \
			src/utils2.c \
			src/ft_isdigit.c \

CC = gcc

FLAGS = -c -Wall -Wextra

INCLUDE = includes/push_swap.h

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCLUDE)
		@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		@$(CC) -o $(NAME) $(SRCS)
		@printf "\033[0;32m./push_swap succesfully built\e[0m\n"

all : $(NAME)

clean :
		@rm -rf $(OBJS)
		@printf "\033[0;31mfolder cleaned\e[0m\n"

fclean : clean
		@rm -rf $(OBJS)
		@rm -rf $(NAME)
		@printf "\033[0;31mfolder fcleaned\e[0m\n"

re : fclean all

.PHONY: clean fclean re all