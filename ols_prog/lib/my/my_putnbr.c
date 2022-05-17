/*
** EPITECH PROJECT, 2021
** my_putnbr.c
** File description:
** display a number on the standard output
*/

#include "../../include/my.h"
#include <unistd.h>

byte_t my_putnbr_to(long nb, int fd)
{
    long displayable;

    if (nb < 0) {
        write(fd, "-", 1);
        nb = -nb;
    }
    if (nb >= 10) {
        my_putnbr_to(nb / 10, fd);
        displayable = nb % 10 + 48;
    } else
        displayable = nb + 48;
    write(fd, &displayable, 1);
    return 0;
}

byte_t my_putint(int nb)
{
    char displayable;

    if (nb < 0) {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10) {
        my_putint(nb / 10);
        displayable = nb % 10 + 48;
    } else
        displayable = nb + 48;
    write(1, &displayable, 1);
    return 0;
}

byte_t my_putuint(unsigned int nb)
{
    char displayable;

    if (nb >= 10) {
        my_putuint(nb / 10);
        displayable = nb % 10 + 48;
    } else
        displayable = nb + 48;
    write(1, &displayable, 1);
    return 0;
}

byte_t my_putlong(long nb)
{
    char displayable;

    if (nb < 0) {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10) {
        my_putlong(nb / 10);
        displayable = nb % 10 + 48;
    } else
        displayable = nb + 48;
    write(1, &displayable, 1);
    return 0;
}

byte_t my_putulong(unsigned long nb)
{
    char displayable;

    if (nb >= 10) {
        my_putuint(nb / 10);
        displayable = nb % 10 + 48;
    } else
        displayable = nb + 48;
    write(1, &displayable, 1);
    return 0;
}
