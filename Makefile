##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	events.c	\
		events2.c	\
		my_strlen.c	\
		my_rev_putnbr.c	\
		openned_window.c	\
		openned_window2.c	\
		variable_affectation.c	\
		my_getnbr.c	\kayle_anime.c	\
		main.c

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	gcc $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -o $(NAME)

clean:
	rm -rf *~ \#*\# .\#*

fclean:
	rm -f $(NAME)

re:	fclean all clean