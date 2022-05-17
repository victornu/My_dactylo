/*
** EPITECH PROJECT, 2021
** my_wstrlen.c
** File description:
** returns the length of a wchar_t array
*/

#include <stddef.h>
#include "../../include/my.h"

ssize_t my_wstrlen(wchar_t const *wstr)
{
    ssize_t len;

    if (wstr == 0)
        return -1;
    for (len = 0; wstr[len] != 0; len++);
    return len;
}

ssize_t my_wstrlen_until(wchar_t const *wstr, wchar_t const *seps)
{
    ssize_t len;

    if (wstr == 0)
        return -1;
    for (len = 0; wstr[len] != 0 && !wchar_is_in(wstr[len], seps); len++);
    if (wstr[len] == 0)
        return -len;
    return len;
}
