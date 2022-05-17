/*
** EPITECH PROJECT, 2021
** my_nblen.c
** File description:
** give the length of an int
*/

#include "../../include/my.h"

byte_t my_nblen(long nb)
{
    byte_t len = 1;

    if (nb < 0) {
        nb *= -1;
        len++;
    }
    for ( ; nb / 10 > 0; len++)
        nb /= 10;
    return len;
}

byte_t my_intlen(int nb)
{
    byte_t len = 1;

    if (nb < 0) {
        nb *= -1;
        len++;
    }
    for ( ; nb / 10 > 0; len++)
        nb /= 10;
    return len;
}

byte_t my_uintlen(unsigned int nb)
{
    byte_t len = 1;

    for ( ; nb / 10 > 0; len++)
        nb /= 10;
    return len;
}

byte_t my_longlen(long nb)
{
    byte_t len = 1;

    if (nb < 0) {
        nb *= -1;
        len++;
    }
    for ( ; nb / 10 > 0; len++)
        nb /= 10;
    return len;
}

byte_t my_ulonglen(unsigned long nb)
{
    byte_t len = 1;

    for ( ; nb / 10 > 0; len++)
        nb /= 10;
    return len;
}
