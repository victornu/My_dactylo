/*
** EPITECH PROJECT, 2021
** FastFinger
** File description:
** header file for FastFinger Project
*/

#ifndef FAST_FINGER_H_
    #define FAST_FINGER_H_

#define DICTIONARIES_PATH "dictionaries/"

/***  src/dictionaries/  ***/

/* get_dictionaries_name.c */
char **get_dictionaries_name(void);

/* handle_dictionary_selection.c */
char **handle_selection(void);

/* read_dictionary.c */
char *read_dictionary(char *dic_path);

/***  src/terminal_interactions/  ***/

/* activate_raw_mode.c */
void activate_row_mode(int activer);

/* get_input_keycode.c */
int get_input_keycode(void);

/***  src/displays/  ***/

/* display_headers.c */
void display_launch_header(void);
void display_selection_header(void);
void display_begin_header(void);

/* display_selection_list.c */
void display_selection_list(char **list, int select);

#endif
