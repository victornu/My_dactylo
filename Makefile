##
## EPITECH PROJECT, 2021
## Lib Workshop
## File description:
## clear files and run tests
##

SRC	=	src/fast_finger_main.c\
		src/displays/display_headers.c\
		src/displays/display_selection_list.c\
		src/dictionary/get_dictionaries_name.c\
		src/dictionary/handle_dictionary_selection.c\
		src/dictionary/read_dictionary.c\
		src/terminal_interactions/activate_raw_mode.c\
		src/terminal_interactions/get_input_keycode.c

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

CFLAGS	=	-g

LFLAGS	=	-L lib/maths -lmaths -L lib/wmy -lwmy -L lib/my -lmy

FLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/maths
	$(MAKE) -C lib/wmy
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(LFLAGS) $(FLAGS)

debug:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/maths
	$(MAKE) -C lib/wmy
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LFLAGS) $(FLAGS)

clean:
	rm $(OBJ)
	$(MAKE) -C lib/my clean
	$(MAKE) -C lib/wmy clean
	$(MAKE) -C lib/maths clean

fclean:
	rm $(NAME)
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/wmy fclean
	$(MAKE) -C lib/maths fclean
	rm $(OBJ)

re:
	$(MAKE) fclean
	$(MAKE) all
