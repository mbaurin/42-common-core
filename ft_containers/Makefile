NAME = ft_containers

FLAGS =	-Wall -Wextra -Iinc/

SRC = ./src/main.cpp \
		./src/vector.cpp \
		./src/map.cpp

HEADER = ./includes/avlIterator.hpp \
			./includes/avlTree.hpp \
			./includes/map.hpp \
			./includes/pair.hpp \
			./includes/reverseIterator.hpp \
			./includes/test.hpp \
			./includes/utils.hpp \
			./includes/utilsIterator.hpp \
			./includes/vector.hpp \
			./includes/vectorIterator.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(HEADER)
	@c++ $(FLAGS) $(FLAGS_H) -c $< -o $@

$(NAME): $(OBJ)
	@c++ $(FLAGS) $(FLAGS_H) $(OBJ) -o $(NAME)
	@echo "\033[1;32m./$(NAME)"

clean:
	@rm -f $(OBJ)
	@echo "\033[1;31mObjects Deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31mExecutable Deleted"

re:	fclean all

.PHONY: all, clean, fclean, re
