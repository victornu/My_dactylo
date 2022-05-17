/*
** EPITECH PROJECT, 2021
** my_wcharsize.c
** File description:
** returns the size of a wide char
*/

#include <stdlib.h>

ssize_t my_wcharsize(wchar_t wc)
{
    ssize_t n_byte = 0;

    while (n_byte < 4 && wc >> (8 * n_byte))
        n_byte++;
    return n_byte ? n_byte : 1;
}
