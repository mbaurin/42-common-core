NAME = animals

SRC	=	main.cpp \
		Animal.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Dog.cpp \
		Brain.cpp

OBJ = $(SRC:.cpp=.o)

CLANG = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(OBJ) -o $@
	@printf "\\033[0;32m./animals built\e[0m\n"

%.o:%.cpp
	@$(CLANG) $(FLAGS) -o $@ -c $<

$(OBJ): Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

clean:
	@rm -rf $(OBJ)
	@printf "\033[0;31mfolder cleaned\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[0;31mfolder fcleaned\e[0m\n"

re:	fclean all

.PHONY: all clean fclean re