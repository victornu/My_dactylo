/*
** EPITECH PROJECT, 2021
** my_putwstr.c
** File description:
** put a wide character array
*/

#include "../../include/wmy.h"

ssize_t my_putwstr(wchar_t const *wstr)
{
    ssize_t size;

    if (!wstr)
        return -1;
    for (size = 0; wstr[size] != 0; size++);
    return my_wwrite(1, wstr, size);
}

ssize_t my_putwstrarr(wchar_t **wstrarr, wchar_t *sep)
{
    ssize_t size = 0;
    ssize_t s_buff;

    if (wstrarr == NULL)
        return -1;
    while (*wstrarr) {
        s_buff = my_putwstr(*wstrarr++);
        size += s_buff > 0 ? s_buff : 0;
        if (sep != NULL && *wstrarr != NULL) {
            s_buff = my_putwstr(sep);
            size += s_buff > 0 ? s_buff : 0;
        }
    }
    return size;
}
