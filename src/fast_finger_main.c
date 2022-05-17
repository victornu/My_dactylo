/*
** EPITECH PROJECT, 2021
** FastFinger
** File description:
** main function to launch FastFinger
*/

#include "../include/my.h"
#include "../include/fast_finger.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    int keycode;
    char **words;

    activate_row_mode(1);
    display_launch_header();
    words = handle_selection();
    if (!words)
        return 84;
    my_putstrarr(words, "\n\r");
    free_strarr(words);
    activate_row_mode(0);
    return 0;
}
