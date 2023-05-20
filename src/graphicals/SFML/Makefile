##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/SFML_LIB.cpp	\
		src/Sprite.cpp

LIB_PATH	=	../../../lib

MV	=	mv

CC	=	g++

NAME	=	arcade_sfml.so

CPPFLAGS	=	-iquote ../../../include/

CFLAGS	=	-std=c++20 -Wall -Wextra

LDFLAGS	=	-lsfml-system -lsfml-window -lsfml-network -lsfml-graphics -lsfml-audio

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
