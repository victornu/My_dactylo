/*
** EPITECH PROJECT, 2021
** my_putnbr_base.c
** File description:
** converts and returns a number in a given base into a decimal number
*/

#include <unistd.h>
#include "../../../include/maths.h"

int my_getnbr_base(char const *str, char const *base)
{
    int nbr = 0;
    int sign = 1;
    size_t s_len;
    size_t b_len;
    size_t i;

    while (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -sign;
    for (s_len = 0; str[s_len] != 0; s_len++);
    for (b_len = 0; base[b_len] != 0; b_len++);
    for (int n = --s_len; n >= 0; n--) {
        for (i = 0; i < b_len && base[i] != str[n]; i++);
        if (i == b_len)
            return sign * 0;
        nbr += i * power(b_len, s_len - n);
    }
    return sign * nbr;
}
