/*
** EPITECH PROJECT, 2021
** my_skipwchar.c
** File description:
** skip a wide character from a byte_t* and returns it
*/

#include "../../include/my.h"
#include <stdlib.h>

wchar_t my_skipwchar(byte_t **cp)
{
    wchar_t utf8 = 0;
    int n_b;

    if (cp == NULL || *cp == NULL)
        return 0;
    for (n_b = 0; n_b <= 4 && (**cp >> (7 - n_b)) & 1; n_b++);
    n_b = n_b ? n_b - 1 : 0;
    if (n_b) {
        for (int byte = n_b; byte >= 0; byte--)
            utf8 += (*(*cp)++ << (8 * byte));
    } else
        return *(*cp)++;
    return utf8;
}
