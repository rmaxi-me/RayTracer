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
CPPFLAGS =	-I./Engine/include/Engine -Wall -Wextra -Weffc++ -std=c++17

all:		$(NAME)

unit_tests:	LDFLAGS		+= -lcriterion --coverage
unit_tests:	CPPFLAGS	+= --coverage
unit_tests:	fclean $(OBJ)
			$(CXX) -o tests_run $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ) $(OBJ_UNIT)

fclean:		clean
			$(RM) $(NAME) tests_run

re:			fclean all

cov_gen:
			@gcovr -s --exclude tests

cov_clean:
			find . \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

bigclean:       fclean cov_clean

.PHONY:		all clean fclean re cov_gen cov_clean unit_tests bigclean
