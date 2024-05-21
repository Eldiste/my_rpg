##
## EPITECH PROJECT, 2022
## MAKEFIL
## File description:
## MAKEFIL
##

SRC	=	$(shell find . -type f -name "*.c")

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -W -Wextra -Wall -g3

LDFLAGS = -lm

CSFMLFLAGS	= -lcsfml-graphics \
			-lcsfml-audio \
			-lcsfml-window \
			-lcsfml-system

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) $(CSFMLFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(shell find . -type f -name '*.o')

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
