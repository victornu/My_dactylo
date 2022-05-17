/*
** EPITECH PROJECT, 2021
** my_memmove.c
** File description:
** my memmove
*/

#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    if (!src || !dest)
        return dest;
    while (n-- && *((char *) dest))
        ((char *) dest)[n] = ((char *) src)[n];
    return dest;
}
