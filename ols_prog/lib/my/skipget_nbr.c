/*
** EPITECH PROJECT, 2021
** number.c
** File description:
** convert char array to int and place the pointer to the end of number
*/

#include "../../include/my.h"

int skipget_int(char **strptr)
{
    int sign = 1;
    int nbr = 0;

    for (int i = 0; *strptr[i] == '+' || *strptr[i] == '-'; i++) {
        if (*strptr[i] == '-')
            sign = -sign;
    }
    while (nbr * 10 < MAXINT) {
        if (**strptr >= '0' && **strptr <= '9')
            nbr = nbr * 10 + **strptr - '0';
        else
            return sign * nbr;
        (*strptr)++;
    }
    if (**strptr >= '0' && **strptr <= (sign == 1 ? '7' : '8'))
        return sign * (nbr * 10 + **strptr - '0');
    return 0;
}

unsigned int skipget_uint(char **strptr)
{
    unsigned int nbr = 0;

    while (*(*strptr)++ == '+');
    while (nbr * 10 < MAXUINT) {
        if (**strptr >= '0' && **strptr <= '9')
            nbr = nbr * 10 + **strptr - '0';
        else
            return nbr;
        (*strptr)++;
    }
    if (**strptr >= '0' && **strptr <= '5')
        return nbr * 10 + **strptr - '0';
    return 0;
}

long skipget_long(char **strptr)
{
    int sign = 1;
    long nbr = 0;

    for (int i = 0; *strptr[i] == '+' || *strptr[i] == '-'; i++) {
        if (*strptr[i] == '-')
            sign = -sign;
    }
    while (nbr * 10 < MAXLONG) {
        if (**strptr >= '0' && **strptr <= '9')
            nbr = nbr * 10 + **strptr - '0';
        else
            return sign * nbr;
        (*strptr)++;
    }
    if (**strptr >= '0' && **strptr <= (sign == 1 ? '7' : '8'))
        return sign * (nbr * 10 + **strptr - '0');
    return 0;
}

unsigned long skipget_ulong(char **strptr)
{
    unsigned long nbr = 0;

    while (*(*strptr)++ == '+');
    while (nbr * 10 < MAXULONG) {
        if (**strptr >= '0' && **strptr <= '9')
            nbr = nbr * 10 + **strptr - '0';
        else
            return nbr;
        (*strptr)++;
    }
    if (**strptr >= '0' && **strptr <= '5')
        return nbr * 10 + **strptr - '0';
    return 0;
}

long skipget_nbr(char *str)
{
    write(1, "2", 1);
    signed sign = 1;
    int s;

    for (s = 0; str[s] == '+' || str[s] == '-'; s++)
        if (str[s] == '-')
            sign = -sign;
    if (sign == -1) {
        if (my_strcmp(&STR_MININT[1], str + s) >= 0)
            return skipget_int(&str);
        if (my_strcmp(&STR_MINLONG[1], str + s) >= 0)
            return skipget_long(&str);
    }
    if (my_strcmp(STR_MAXUINT, str + s) >= 0)
        return skipget_uint(&str);
    if (my_strcmp(STR_MAXULONG, str + s) >= 0)
        return skipget_ulong(&str);
    return 0;
}
