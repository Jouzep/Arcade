##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/MenuLib.cpp	\
		src/Music.cpp	\
		src/Tile.cpp	\
		src/Text.cpp

LIB_PATH	=	../../../lib

MV	=	mv

CC	=	g++

NAME	=	arcade_menu.so

CPPFLAGS	=	-iquote ../../../include/

CFLAGS	=	-std=c++20 -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) -c -fPIC $(SRC) $(CPPFLAGS)
	$(CC) -shared -o $(NAME) *.o
	$(MV) $(NAME) $(LIB_PATH)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(LIB_PATH)/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
