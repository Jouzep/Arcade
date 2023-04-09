##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	../Music.cpp			\
		../Text.cpp				\
		../Tile.cpp				\
		src/SolarFox.cpp		\
		../ConfHandler.cpp		\
		../FileReader.cpp

LIB_PATH	=	../../../lib

MV	=	mv

CC	=	g++

NAME	=	arcade_solarfox.so

CPPFLAGS	=	-iquote ../../../include/

CFLAGS	=	-std=c++20 -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) -shared -fPIC $(CPPFLAGS) -g3
	$(MV) $(NAME) $(LIB_PATH)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(LIB_PATH)/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
