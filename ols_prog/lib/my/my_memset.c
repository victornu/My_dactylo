/*
** EPITECH PROJECT, 2021
** my_memeset.c
** File description:
** my memset
*/

#include <stddef.h>

void *my_memset(void *s, int const c, size_t n)
{
    if (!s)
        return s;
    while (n && *((int *) s))
        ((int *) s)[--n] = c;
    return s;
}
