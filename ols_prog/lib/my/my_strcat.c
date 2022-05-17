/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** Concatenates two strings.
*/

#include <stddef.h>

char *my_strcat(char *dest, char const *src)
{
    size_t len;
    unsigned int i;

    for (len = 0; dest[len] != 0; len++);
    for (i = 0 ; src[i] != 0; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}

char *my_strncat(char *dest, char const *src, size_t n)
{
    size_t len;
    unsigned int i;

    for (len = 0; dest[len] != 0; len++);
    for (i = 0 ; src[i] != 0 && i < n; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}
