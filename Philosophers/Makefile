NAME = philo
HEADER = ./include/

INC = ./include/philosophers.h

CFLAGS = -Werror -Wall -Wextra -g -I $(HEADER) -pthread

SRC = src/main.c \
		src/utils.c \
		src/parser.c \
		src/check.c \
		src/action.c \
		src/action_utils.c \
		src/init.c \
		src/ft_memory_cleaner2000.c \
		src/memory_utils/ft_lstadd_back.c \
		src/memory_utils/ft_lstadd_front.c \
		src/memory_utils/ft_lstclear.c \
		src/memory_utils/ft_lstdelone.c \
		src/memory_utils/ft_lstiter.c \
		src/memory_utils/ft_lstlast.c \
		src/memory_utils/ft_lstnew.c \
		src/memory_utils/ft_lstsize.c

OBJS = $(SRC:.c=.o)

%.o : %.c	$(INC)
	gcc $(CFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJS)
			gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all