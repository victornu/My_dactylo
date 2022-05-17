/*
** EPITECH PROJECT, 2021
** my_setalloc.c
** File description:
** alloc and set memory to 'buf'
*/

#include "../../include/my_types.h"
#include <stdlib.h>

void *my_setalloc(void **buf, size_t size, byte_t set)
{
    byte_t *ptr = malloc(size);

    for (unsigned int i = 0; i < size; i++)
        ptr[i] = set;
    if (buf)
        *buf = ptr;
    return ptr;
}
