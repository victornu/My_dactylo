/*
** EPITECH PROJECT, 2021
** my_putnbr_base.c
** File description:
** write a decimal number into another base
*/

#include <unistd.h>

int my_putnbr_base(int nbr, char const *base)
{
    ssize_t size = 0;
    size_t b_len;

    if (base == NULL)
        return 0;
    if (nbr < 0) {
        size += write(1, "-", 1);
        nbr = -nbr;
    }
    for (b_len = 0; base[b_len] != 0; b_len++);
    if (nbr && size >= 0) {
        size += my_putnbr_base(nbr / b_len, base);
        size += write(1, &base[nbr % b_len], 1);
        if (size < 1)
            return -1;
    }
    return size;
}
