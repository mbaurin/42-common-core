NAME = materia

SRC	=	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

CLANG = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(OBJ) -o $@
	@printf "\\033[0;32m./materia built\e[0m\n"

%.o:%.cpp
	@$(CLANG) $(FLAGS) -o $@ -c $<

$(OBJ): AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.cpp

clean:
	@rm -rf $(OBJ)
	@printf "\033[0;31mfolder cleaned\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[0;31mfolder fcleaned\e[0m\n"

re:	fclean all

.PHONY: all clean fclean re