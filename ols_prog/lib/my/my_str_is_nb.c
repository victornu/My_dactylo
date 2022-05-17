/*
** EPITECH PROJECT, 2021
** ../lib/my
** File description:
** header for ../lib/my/
*/

#include "../../include/my.h"

byte_t my_str_is_int(char *str)
{
    if (!str)
        return 0;
    if (*str == '-')
        str++;
    while (*str) {
        if (!IS_NUM(*str))
            return 0;
        str++;
    }
    return 1;
}

byte_t my_str_is_uint(char *str)
{
    if (!str)
        return 0;
    while (*str) {
        if (!IS_NUM(*str))
            return 0;
        str++;
    }
    return 1;
}
