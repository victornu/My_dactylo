/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** my strdup
*/

#include <stdlib.h>

char *my_strdup(char const *s)
{
    char *dup;
    size_t len;

    for (len = 0; s[len] != 0; len++);
    dup = malloc(sizeof(char) * (len + 1));
    while (*s != 0)
        *dup++ = *s++;
    *dup = 0;
    dup -= len;
    return (dup);
}

char *my_strndup(char const *s, size_t n)
{
    char *dup;
    size_t len;

    dup = malloc(sizeof(char) * (n + 1));
    for (len = 0; *s != 0 && n > len; len++)
        dup[len] = s[len];
    dup[len] = 0;
    return (dup);
}

char **my_strarrdup(char **strarr)
{
    int arrlen;
    char **dup;

    for (arrlen = 0; strarr[arrlen]; arrlen++);
    dup = malloc(sizeof(void *) * (arrlen + 1));
    dup[arrlen] = NULL;
    while (arrlen--)
        dup[arrlen] = my_strdup(strarr[arrlen]);
    return dup;
}
