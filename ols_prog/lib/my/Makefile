##
## EPITECH PROJECT, 2021
## libmy.a
## File description:
## Makefile to make libmy.a
##

SRC	=	my_memset.c\
		my_memmove.c\
		my_putchar.c\
		my_putstr.c\
		my_strlen.c\
		my_putnbr.c\
		my_getnbr.c\
		my_nblen.c\
		ntoa.c\
		my_strcat.c\
		my_strcpy.c\
		my_strdup.c\
		my_revstr.c\
		my_strcmp.c\
		my_str_is_nb.c\
		word_tools.c\
		my_str_to_word_array.c\
		is_in.c\
		my_putnbr_base.c\
		my_getnbr_base.c\
		base_converter.c\
		my_transform_str.c\
		skipget_nbr.c\
		free_ptrarr.c\
		si_dictionary.c\
		get_si_dic.c

DEPENDENCIES	=	power.c

OBJ	=	$(SRC:.c=.o) $(DEPENDENCIES:.c=.o)

NAME	=	libmy.a

FLAGS	=	-W -Wall -Wextra

all:
	gcc -c $(SRC) $(FLAGS)
	$(MAKE) load_dependencies
	ar rc $(NAME) $(OBJ)

do_clearly:
	gcc -c $(SRC) $(FLAGS)
	$(MAKE) load_dependencies
	ar rc $(NAME) $(OBJ)
	rm $(OBJ)

load_dependencies:
	cd dependencies && gcc -c $(DEPENDENCIES) $(FLAGS)
	mv dependencies/*.o .

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)
	make clean

re:
	rm $(NAME)
	make all
