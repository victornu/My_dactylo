/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** handle selection of dictionary
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/fast_finger.h"

void handle_selection_loop(char **names, size_t num_names, int *select)
{
    int keycode = 0;

    write(1, "\n\r", 1);
    while (keycode != 10 && keycode != 13 && keycode != 32) {
        write(1, "\033[A", 3);
        display_selection_list(names, *select);
        keycode = get_input_keycode();
        if (keycode == 4414235 && *select < num_names - 1)
            (*select)++;
        else if (keycode == 4479771 && *select > 0)
            (*select)--;
    }
}

int select_dictionary(char **dictionaries_name)
{
    size_t num_dic;
    static int select = 0;

    if (!dictionaries_name || !*dictionaries_name) {
        write(2, "\rCannot find any dictionary to use\n\r", 36);
        return -1;
    }
    for (num_dic = 0; dictionaries_name[num_dic]; num_dic++);
    display_selection_header();
    handle_selection_loop(dictionaries_name, num_dic, &select);
    return select;
}

char **handle_selection(void)
{
    char **dictionaries = get_dictionaries_name();
    ssize_t select = select_dictionary(dictionaries);
    char **words;
    char *dic_buf;

    if (select == -1)
        return NULL;
    dic_buf = read_dictionary(dictionaries[select]);
    free_strarr(dictionaries);
    if (!dic_buf)
        return NULL;
    words = my_strtok(dic_buf, "\n");
    free(dic_buf);
    return words;
}
