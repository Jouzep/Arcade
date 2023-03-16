##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SFML_PATH	=	SFML/
SDL2_PATH	=	SDL2/
NCURSE_PATH	=	Ncurse/

all:
	$(MAKE) -C $(SFML_PATH)
	$(MAKE) -C $(SDL2_PATH)
	$(MAKE) -C $(NCURSE_PATH)

clean:
	$(MAKE) clean -C $(SFML_PATH)
	$(MAKE) clean -C $(SDL2_PATH)
	$(MAKE) clean -C $(NCURSE_PATH)

fclean:	clean
	$(MAKE) fclean -C $(SFML_PATH)
	$(MAKE) fclean -C $(SDL2_PATH)
	$(MAKE) fclean -C $(NCURSE_PATH)

re:	fclean all

.PHONY: all clean fclean re
