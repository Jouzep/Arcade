##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/NCurseLib.cpp

LIB_PATH	=	../../../lib

MV	=	mv

CC	=	g++

NAME	=	arcade_ncurses.so

CPPFLAGS	=	-iquote ../../../include/ -g3

LDFLAGS = -lncurses

CFLAGS	=	-std=c++20 -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) -c -fPIC $(SRC) $(CPPFLAGS)
	$(CC) -shared -o $(NAME) *.o $(LDFLAGS)
	$(MV) $(NAME) $(LIB_PATH)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(LIB_PATH)/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
