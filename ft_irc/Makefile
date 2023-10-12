NAME = ircserv 

CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = src/main.cpp \
		src/server.cpp \
		src/client.cpp \
		src/command.cpp \
		src/channel.cpp \
		src/commands/pass.cpp \
		src/commands/nick.cpp \
		src/commands/user.cpp \
		src/commands/quit.cpp \
		src/commands/oper.cpp \
		src/commands/mode.cpp \
		src/commands/join.cpp \
		src/commands/part.cpp \
		src/commands/ping.cpp \
		src/commands/privmsg.cpp \
		src/commands/notice.cpp \
		src/commands/invite.cpp \
		src/commands/topic.cpp \
		src/commands/names.cpp \
		src/commands/list.cpp \
		src/commands/kick.cpp \
		src/commands/bot.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CXXFLAGS) $^ -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
