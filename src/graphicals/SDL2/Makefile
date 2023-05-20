##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/SDL2_LIB.cpp

LIB_PATH	=	../../../lib

MV	=	mv

CC	=	g++

NAME	=	arcade_sdl2.so

CPPFLAGS	=	-iquote ../../../include/

LDFLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -g3

CFLAGS	=	-std=c++20 -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) -c -fPIC $(SRC)  $(CPPFLAGS)
	$(CC) -shared -o $(NAME) *.o $(LDFLAGS)
	$(MV) $(NAME) $(LIB_PATH)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(LIB_PATH)/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
