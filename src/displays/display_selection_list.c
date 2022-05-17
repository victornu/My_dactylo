/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** handle selection of dictionary
*/

#include <unistd.h>
#include "../../include/my.h"

void display_selection_list(char **list, int select)
{
    write(1, "\r|", 2);
    for (int s = 0; list[s]; s++) {
        if (s == select)
            write(1, "\033[1m", 4);
        write(1, " ", 1);
        my_putstr(list[s]);
        if (s == select)
            write(1, "\033[0m", 4);
        write(1, " |", 2);
    }
    write(1, "\n\r", 2);
}
