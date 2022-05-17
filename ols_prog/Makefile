##
## EPITECH PROJECT, 2021
## Lib Workshop
## File description:
## clear files and run tests
##

SRC	=	main.c\
		display.c

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

LFLAGS	=	-L lib/maths -lmaths -L lib/wmy -lwmy -L lib/my -lmy

FLAGS	=	-W -Wall -Wextra

all:
	$(MAKE) -C lib/maths
	$(MAKE) -C lib/wmy
	$(MAKE) -C lib/my
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LFLAGS) $(FLAGS)

clean:
	rm $(OBJ)
	$(MAKE) -C lib/my clean
	$(MAKE) -C lib/wmy clean
	$(MAKE) -C lib/maths clean

tests_run:
	$(MAKE) -C tests/libmy all

fclean:
	rm $(NAME)
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/wmy fclean
	$(MAKE) -C lib/maths fclean
	$(MAKE) clean

re:
	$(MAKE) all
