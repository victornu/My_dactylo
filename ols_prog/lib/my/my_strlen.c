/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** returns the length of a char array
*/

#include <unistd.h>
#include "../../include/my.h"

ssize_t my_strlen(char const *str)
{
    ssize_t len;

    if (str == 0)
        return -1;
    for (len = 0; str[len] != 0; len++);
    return len;
}

short my_strshortlen(char const *str)
{
    short len;

    if (str == 0)
        return -1;
    for (len = 0; str[len] != 0 && len < MAXSHORT; len++);
    return len;
}

long my_strlonglen(char const *str)
{
    long len;

    if (str == 0)
        return -1;
    for (len = 0; str[len] != 0 && len < MAXLONG; len++);
    return len;
}

ssize_t my_strlen_until(char const *str, char const *seps)
{
    ssize_t len;

    if (str == 0)
        return -1;
    for (len = 0; str[len] != 0 && !char_is_in(str[len], seps); len++);
    if (str[len] == 0)
        return -len;
    return len;
}

ssize_t my_strarrlen(char **starr)
{
    ssize_t len;

    if (starr == NULL)
        return -1;
    for (len = 0; *starr++; len++);
    return len;
}
