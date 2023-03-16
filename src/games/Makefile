##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

PACMAN_PATH	=	pacman/
SNAKE_PATH	=	snake/

all:
	$(MAKE) -C $(PACMAN_PATH)
	$(MAKE) -C $(SNAKE_PATH)

clean:
	$(MAKE) clean -C $(PACMAN_PATH)
	$(MAKE) clean -C $(SNAKE_PATH)

fclean:	clean
	$(MAKE) fclean -C $(PACMAN_PATH)
	$(MAKE) fclean -C $(SNAKE_PATH)

re:	fclean all

.PHONY: all clean fclean re
