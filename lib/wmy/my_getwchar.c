/*
** EPITECH PROJECT, 2021
** my_getwchar.c
** File description:
** get a wide character from a byte_t*
*/

#include "../../include/wmy.h"

wchar_t my_getwchar(byte_t *cp)
{
    wchar_t utf8 = 0;
    int n_b;

    if (cp == NULL)
        return 0;
    for (n_b = 0; n_b <= 4 && (*cp >> (7 - n_b)) & 1; n_b++);
    n_b = n_b ? n_b - 1 : 0;
    if (n_b) {
        for (int byte = n_b; byte >= 0; byte--)
            utf8 += (*cp++ << (8 * byte));
    } else
        return *cp;
    return utf8;
}
