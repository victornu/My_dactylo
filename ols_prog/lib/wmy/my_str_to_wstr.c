/*
** EPITECH PROJECT, 2021
** my_str_to_wstr.c
** File description:
** convert a simple char array 'str' to an wchar_t array 'wstr'
*/

#include "../../include/wmy.h"
#include "../../include/my.h"
#include <stdlib.h>

wchar_t *my_str_to_wstr(char const *str)
{
    ssize_t len = my_strlen(str);
    wchar_t *wstr = malloc(sizeof(wchar_t) * (len + 1));

    if (!str)
        return NULL;
    for (int i = 0; i < len; i++)
        wstr[i] = my_skipwchar((byte_t **) &str);
    return wstr;
}
