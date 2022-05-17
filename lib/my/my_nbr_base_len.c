/*
** EPITECH PROJECT, 2021
** my_nbr_base_len.c
** File description:
** handle identifiers
*/

#include <stdio.h>

size_t my_nbr_base_len(long nbr, char const *base)
{
    size_t size;
    size_t b_len;

    if (nbr == 0)
        return 1;
    for (b_len = 0; base[b_len]; b_len++);
    for (size = 0; nbr; size++)
        nbr /= b_len;
    return size;
}
