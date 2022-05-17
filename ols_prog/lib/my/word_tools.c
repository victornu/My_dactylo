/*
** EPITECH PROJECT, 2021
** word_tools.c
** File description:
** file for word tools func
*/

#include "../../include/my.h"

int is_word_start(char const *str, int i, char const *seps)
{
    return
    !char_is_in(str[i], seps) && (i == 0 || char_is_in(str[i - 1], seps));
}

int is_word_end(char const *str, int i, char const *seps)
{
    return
    !char_is_in(str[i], seps) && (i != 0 && char_is_in(str[i - 1], seps));
}

int is_wide_word_start(wchar_t const *str, int i, wchar_t const *seps)
{
    return
    !wchar_is_in(str[i], seps) && (i == 0 || wchar_is_in(str[i - 1], seps));
}
