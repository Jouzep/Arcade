##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CORE_PATH			=	src/core
GAMES_PATH			=	src/games
GRAPHICALS_PATH		=	src/graphicals

all: core games graphicals

core:
	$(MAKE) -C $(CORE_PATH)

games:
	$(MAKE) -C $(GAMES_PATH)

graphicals:
	$(MAKE) -C $(GRAPHICALS_PATH)

clean:
	$(MAKE) clean -C $(CORE_PATH)
	$(MAKE) clean -C $(GAMES_PATH)
	$(MAKE) clean -C $(GRAPHICALS_PATH)

fclean:	clean
	$(MAKE) fclean -C $(CORE_PATH)
	$(MAKE) fclean -C $(GAMES_PATH)
	$(MAKE) fclean -C $(GRAPHICALS_PATH)

re:	fclean all

.PHONY: all debug clean fclean re
