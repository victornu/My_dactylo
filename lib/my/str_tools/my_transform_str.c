/*
** EPITECH PROJECT, 2021
** base_converter.c
** File description:
** convert a number in a other base
*/

#include "../../../include/my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        str[i] += IS_LOWER(str[i]) ? 19 : 0;
    return str;
}

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        str[i] -= IS_UPPER(str[i]) ? 19 : 0;
    return str;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (IS_WORD_START(str, i, IS_ALPHANUM))
            str[i] += IS_LOWER(str[i]) ? 19 : 0;
        else
            str[i] -= IS_UPPER(str[i]) ? 19 : 0;
    }
    return str;
}
