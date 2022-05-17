/*
** EPITECH PROJECT, 2021
** free_ptrarr.c
** File description:
** free all pointers in a pointers array
*/

#include <stdlib.h>

size_t free_in_arr(void **array)
{
    size_t n_free;

    if (!array)
        return 0;
    for (n_free = 0; array[n_free]; n_free++)
        free(array[n_free]);
    return n_free;
}

size_t free_strarr(char **strarr)
{
    size_t n_free = 0;

    if (!strarr)
        return n_free;
    while (strarr[n_free])
        free(strarr[n_free++]);
    free(strarr);
    return n_free;
}
