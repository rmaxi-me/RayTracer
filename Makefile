##
## EPITECH PROJECT, 2020
## YEP_project1_2019
## File description:
## Unit tests Makefile
##

SHELL =		/bin/bash
CXX = 		g++
RM = 		rm -f

SRC =		$(shell find Engine -name "*.cpp" 2> /dev/null) $(shell find Tests -name "*.cpp" 2> /dev/null)
OBJ =		$(SRC:.cpp=.o)

NAME =		unit_tests
CXXFLAGS =	-Wall -Wextra -Weffc++ -std=c++17 --coverage
CPPFLAGS =	-I./Engine/include -I./Engine/include/Engine -I./Dependencies/raylib/src
LDFLAGS	=	-lraylib -lcriterion --coverage

all:		$(NAME)

ci:			fclean $(NAME) run cov_gen bigclean

run:
			@echo "::debug ====== TESTS RUN ======"
			./$(NAME) --verbose -j1 -S --timeout 30

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ) $(OBJ_UNIT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

cov_gen:
			@echo "::debug ====== CODE COVERAGE ======"
			@gcovr -s --exclude tests

cov_clean:
			find . \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

bigclean:	fclean cov_clean

.PHONY:		all clean fclean re cov_gen cov_clean bigclean ci run
