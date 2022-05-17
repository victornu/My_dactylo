/*
** EPITECH PROJECT, 2021
** FastFinger
** File description:
** read keyboard's input and return it code
*/

#include <unistd.h>

int get_input_keycode(void)
{
    long key = 0;

    read(0, &key, sizeof(int));
    return key;
}
