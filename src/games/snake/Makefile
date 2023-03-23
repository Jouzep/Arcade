##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/Snake.cpp 			\
		src/SnakeBody.cpp		\
		src/SnakeFood.cpp		\
		../Music.cpp			\
		../Text.cpp				\
		../Tile.cpp

LIB_PATH	=	../../../lib

MV	=	mv

CC	=	g++

NAME	=	arcade_snake.so

CPPFLAGS	=	-iquote ../../../include/ -g3

CFLAGS	=	-std=c++20 -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) -shared -fPIC $(CPPFLAGS)
#	$(CC) -shared -o $(NAME) *.o
	$(MV) $(NAME) $(LIB_PATH)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(LIB_PATH)/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
