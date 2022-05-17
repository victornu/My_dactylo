/*
** EPITECH PROJECT, 2021
** my_wstrdup.c
** File description:
** returns a pointer to a new wchar_t string
** which is a duplicate of the wchar_t string s
*/

#include <stdlib.h>

wchar_t *my_wstrdup(wchar_t const *s)
{
    wchar_t *dup;
    size_t len;

    for (len = 0; s[len] != 0; len++);
    dup = malloc(sizeof(wchar_t) * (len + 1));
    while (*s != 0)
        *dup++ = *s++;
    *dup = 0;
    dup -= len;
    return (dup);
}

wchar_t *my_wstrndup(wchar_t const *s, size_t n)
{
    wchar_t *dup;
    size_t len;

    dup = malloc(sizeof(wchar_t) * (n + 1));
    for (len = 0; *s != 0 && n > len; len++)
        dup[len] = s[len];
    dup[len] = 0;
    return (dup);
}

wchar_t **my_wstrarrdup(wchar_t **wstrarr)
{
    int arrlen;
    wchar_t **dup;

    for (arrlen = 0; wstrarr[arrlen]; arrlen++);
    dup = malloc(sizeof(void *) * (arrlen + 1));
    dup[arrlen] = NULL;
    while (arrlen--)
        dup[arrlen] = my_wstrdup(wstrarr[arrlen]);
    return dup;
}

wchar_t **my_wstrarrndup(wchar_t **wstrarr, size_t n)
{
    int arrlen;
    wchar_t **dup;
    size_t nb;

    for (arrlen = 0; wstrarr[arrlen]; arrlen++);
    dup = malloc(sizeof(void *) * (arrlen + 1));
    for (nb = 0; nb < n && wstrarr[nb]; nb++)
        dup[nb] = my_wstrdup(wstrarr[nb]);
    dup[nb] = NULL;
    return dup;
}
