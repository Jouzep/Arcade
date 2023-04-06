##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=			src/Error.cpp	\
				src/Parsing.cpp	\
				src/Core.cpp

MAIN_FILE	=	src/Main.cpp

ROOT_PATH	=	../../

# TEST_FILES = tests/test_project.cpp

MV	=	mv

CC	=	g++

# TEST_NAME	=	unit_tests

NAME	=	arcade

CPPFLAGS	=	-iquote ../../include/ -g3

CFLAGS	=	-std=c++20 -Wall -Wextra

LDFLAGS	=	-fno-gnu-unique -ldl

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(MAIN_FILE) $(COMPONENTS_SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)
	$(MV) $(NAME) $(ROOT_PATH)

# tests_run:
# 	$(CC) $(SRC) $(COMPONENTS_SRC) $(TEST_FILES) $(CPPFLAGS) -o $(TEST_NAME) -lcriterion --coverage
# 	./${TEST_NAME}
# 	gcovr --exclude tests/
# 	gcovr --exclude tests/ --branches

debug:
	$(CC) -o $(NAME) $(SRC) $(MAIN_FILE) $(COMPONENTS_SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -g3
	$(MV) $(NAME) $(ROOT_PATH)

clean:
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(ROOT_PATH)/$(NAME)
	$(RM) $(TEST_NAME)

re:	fclean all

.PHONY: all debug clean fclean re
