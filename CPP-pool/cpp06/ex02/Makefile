NAME = trueType

SRC	=	main.cpp \
		Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp

OBJ = $(SRC:.cpp=.o)

CLANG = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(OBJ) -o $@
	@printf "\\033[0;32m./trueType built\e[0m\n"

%.o:%.cpp
	@$(CLANG) $(FLAGS) -o $@ -c $<

$(OBJ): A.hpp B.hpp C.hpp Base.hpp

clean:
	@rm -rf $(OBJ)
	@printf "\033[0;31mfolder cleaned\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[0;31mfolder fcleaned\e[0m\n"

re:	fclean all

.PHONY: all clean fclean re