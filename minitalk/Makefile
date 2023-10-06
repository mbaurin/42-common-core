SERVER   = server
CLIENT   = client

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

SRCS = src/server.c \
	 src/utils_server.c \
	 src/client.c \
	 src/utils_client.c

OBJS = $(SRCS:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : src/server.o src/utils_server.o includes/minitalk.h
	@$(CC) src/server.o src/utils_server.o -o $@
	@printf "\033[0;32m./server build\e[0m\n"

$(CLIENT) : src/client.o src/utils_client.o includes/minitalk.h
	@$(CC) src/client.o src/utils_client.o -o $@
	@printf "\\033[0;32m./client build\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	@printf "\033[0;31mfolder cleaned\e[0m\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\033[0;31mfolder fcleaned\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
