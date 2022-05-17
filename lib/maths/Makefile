##
## EPITECH PROJECT, 2021
## libmaths.a
## File description:
## Makefile to make libmaths.a
##

SRC	=	factorial.c\
		power.c\
		square_root.c\
		exponential.c\
		sinus.c\
		cosinus.c\
		tangent.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmaths.a

FLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

do_clearly:
	$(MAkE) all
	$(MAKE) clean

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)
	make clean

re:
	$(MAKE) fclean
	$(MAKE) all
