##
## EPITECH PROJECT, 2021
## libmy.a
## File description:
## Makefile to make libmy.a
##

SRC	=	my_setalloc.c\
		my_memset.c\
		my_memmove.c\
		my_putchar.c\
		my_putnbr.c\
		my_nblen.c\
		my_putnbr_base.c\
		my_nbr_base_len.c\
		base_converter.c\
		free_ptrarr.c\
		\
		str_tools/my_putstr.c\
		str_tools/my_strlen.c\
		str_tools/my_getnbr.c\
		str_tools/my_getnbr_base.c\
		str_tools/ntoa.c\
		str_tools/my_strcat.c\
		str_tools/my_strcpy.c\
		str_tools/my_strdup.c\
		str_tools/my_revstr.c\
		str_tools/my_strcmp.c\
		str_tools/my_strspn.c\
		str_tools/my_strstr.c\
		str_tools/my_str_is_nb.c\
		str_tools/word_tools.c\
		str_tools/my_strtok.c\
		str_tools/is_in.c\
		str_tools/my_transform_str.c\
		str_tools/skipget_nbr.c\
		\
		my_printf/my_printf.c\
		my_printf/identifiers_handling.c\
		my_printf/var_handling.c\
		\
		dictionaries/si_dictionary.c\
		dictionaries/increase_dsi.c\
		dictionaries/get_dsi.c\
		\
		dependencies/power.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

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
