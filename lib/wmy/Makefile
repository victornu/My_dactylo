##
## EPITECH PROJECT, 2021
## libmaths.a
## File description:
## Makefile to make libmaths.a
##

SRC	=	my_wcharsize.c\
		my_getwchar.c\
		my_skipwchar.c\
		my_wwrite.c\
		my_putwstr.c\
		my_str_to_wstr.c\
		my_wstr_to_array.c\
		my_wstrcmp.c\
		my_wstrdup.c\
		my_wstrlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libwmy.a

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
