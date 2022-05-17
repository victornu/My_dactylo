/*
** EPITECH PROJECT, 2021
** is_in.c
** File description:
** all verifications of flags types
*/

#include "../../include/wmy.h"

int wchar_is_in(wchar_t const c, wchar_t const *in)
{
    for (int i = 0; in[i] != 0; i++)
        if (in[i] == c)
            return 1;
    return 0;
}

int wstr_is_in_wstrarr(wchar_t const *wstr, wchar_t **wstrarr)
{
    if (!wstr || !wstrarr)
        return 0;
    while (*wstrarr != 0)
        if (!my_wstrcmp(*wstrarr++, wstr))
            return 1;
    return 0;
}
