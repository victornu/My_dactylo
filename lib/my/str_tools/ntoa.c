/*
** EPITECH PROJECT, 2021
** ntoa.c
** File description:
** transform number to char array
*/

#include "../../../include/my.h"
#include <stdlib.h>

char *itoa(int i)
{
    int len = my_intlen(i);
    char *a = malloc(len);
    short sign = 0;

    if (i < 0) {
        i = -i;
        *a = '-';
        sign++;
    }
    while (len-- != sign) {
        a[len] = i % 10 + 48;
        i /= 10;
    }
    return a;
}

char *uitoa(unsigned int i)
{
    int len = my_intlen(i);
    char *a = malloc(len);

    while (len-- > 0) {
        a[len] = i % 10 + 48;
        i /= 10;
    }
    return a;
}

char *ltoa(long i)
{
    int len = my_intlen(i);
    char *a = malloc(len);
    short sign = 0;

    if (i < 0) {
        i = -i;
        *a = '-';
        sign++;
    }
    while (len-- != sign) {
        a[len] = i % 10 + 48;
        i /= 10;
    }
    return a;
}

char *ultoa(unsigned long i)
{
    int len = my_intlen(i);
    char *a = malloc(len);

    while (len-- > 0) {
        a[len] = i % 10 + 48;
        i /= 10;
    }
    return a;
}
