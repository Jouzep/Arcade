##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

MENU_PATH		=	menu/
PACMAN_PATH		=	pacman/
SNAKE_PATH		=	snake/
NIBBLER_PATH 	= 	nibbler/
SOLARFOX_PATH	=	solarfox/

all:
	$(MAKE) -C $(MENU_PATH)
	$(MAKE) -C $(PACMAN_PATH)
	$(MAKE) -C $(SNAKE_PATH)
	$(MAKE) -C $(NIBBLER_PATH)
	$(MAKE) -C $(SOLARFOX_PATH)

clean:
	$(MAKE) clean -C $(MENU_PATH)
	$(MAKE) clean -C $(PACMAN_PATH)
	$(MAKE) clean -C $(SNAKE_PATH)
	$(MAKE) clean -C $(SOLARFOX_PATH)

fclean:	clean
	$(MAKE) fclean -C $(MENU_PATH)
	$(MAKE) fclean -C $(PACMAN_PATH)
	$(MAKE) fclean -C $(SNAKE_PATH)
	$(MAKE) fclean -C $(SOLARFOX_PATH)

re:	fclean all

.PHONY: all clean fclean re
