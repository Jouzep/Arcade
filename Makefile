##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	Foo.cpp

NAME	=	lib.so

CPPFLAGS	=	-iquote ./include/

CFLAGS	=	-std=c++20 -Wall -Wextra

all:	$(NAME)

$(NAME):
	g++ -c -fPIC $(SRC)
	g++ -shared -o $(NAME) *.o
	g++ Main.cpp -ldl

debug:
	$(CC) -o $(NAME) $(SRC) -g3

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all debug clean fclean re
