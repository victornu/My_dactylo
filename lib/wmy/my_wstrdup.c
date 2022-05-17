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
