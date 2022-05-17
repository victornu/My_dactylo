##
## EPITECH PROJECT, 2021
## libmaths.a
## File description:
## Makefile to make libmaths.a
##

SRC	=	power.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmaths.a

FLAGS	=	-W -Wall -Wextra

all:
	gcc -c $(SRC) $(FLAGS)
	ar rc $(NAME) $(OBJ)

do_clearly:
	gcc -c $(SRC) $(FLAGS)
	ar rc $(NAME) $(OBJ)
	rm $(OBJ)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)
	make clean

re:
	rm $(NAME)
	make all
