/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** returns the first number of the input string
*/

#include "../../../include/my.h"

int my_getint(char const *str)
{
    short sign = 1;
    int nbr = 0;

    while (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -sign;
    while (nbr * 10 < 2147483640) {
        if (*str >= '0' && *str <= '9')
            nbr = nbr * 10 + *str - '0';
        else
            return sign * nbr;
        str++;
    }
    if (*str >= '0' && *str <= (sign == 1 ? '7' : '8'))
        return sign * (nbr * 10 + *str - '0');
    return 0;
}

unsigned int my_getuint(char const *str)
{
    short sign = 1;
    unsigned int nbr = 0;

    while (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -sign;
    if (sign != 1)
        return 0;
    while (nbr * 10 < 4294967290) {
        if (*str >= '0' && *str <= '9')
            nbr = nbr * 10 + *str - '0';
        else
            return nbr;
        str++;
    }
    if (*str >= '0' && *str <= '5')
        return nbr * 10 + *str - '0';
    return 0;
}

long my_getlong(char const *str)
{
    short sign = 1;
    long nbr = 0;

    while (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -sign;
    while (nbr * 10 < 9223372036854775800) {
        if (*str >= '0' && *str <= '9')
            nbr = nbr * 10 + *str - '0';
        else
            return sign * nbr;
        str++;
    }
    if (*str >= '0' && *str <= (sign == 1 ? '7' : '8'))
        return sign * (nbr * 10 + *str - '0');
    return 0;
}

unsigned long my_getulong(char const *str)
{
    short sign = 1;
    unsigned long nbr = 0;

    while (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -sign;
    if (sign != 1)
        return 0;
    while (nbr * 10 < 18446744073709551610ULL) {
        if (*str >= '0' && *str <= '9')
            nbr = nbr * 10 + *str - '0';
        else
            return nbr;
        str++;
    }
    if (*str >= '0' && *str <= '5')
        return nbr * 10 + *str - '0';
    return 0;
}

long my_getnbr(char const *str)
{
    short sign = 1;
    int s;

    for (s = 0; str[s] == '+' || str[s] == '-'; s++) {
        if (str[s] == '-')
            sign = -sign;
    }
    if (sign == -1) {
        if (my_strcmp(&STR_MININT[1], str + s) >= 0)
            return my_getint(str);
        if (my_strcmp(&STR_MINLONG[1], str + s) >= 0)
            return my_getlong(str);
    }
    if (my_strcmp(STR_MAXUINT, str + s) >= 0)
        return my_getuint(str);
    if (my_strcmp(STR_MAXULONG, str + s) >= 0)
        return my_getulong(str);
    return 0;
}
