/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** Copies a string into another.
*/

#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    unsigned int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, size_t n)
{
    unsigned int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for ( ; i <= n; i++)
        dest[i] = '\0';
    return dest;
}
