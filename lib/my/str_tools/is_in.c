/*
** EPITECH PROJECT, 2021
** is_in.c
** File description:
** all verifications of flags types
*/

#include "../../../include/my.h"

int char_is_in(char const c, char const *in)
{
    for (int i = 0; in[i] != 0; i++)
        if (in[i] == c)
            return 1;
    return 0;
}

int wchar_is_in(wchar_t const c, wchar_t const *in)
{
    for (int i = 0; in[i] != 0; i++)
        if (in[i] == c)
            return 1;
    return 0;
}

int in_str_is_in(char const *str, char const *in)
{
    int isin = 0;

    for (int i = 0; str[i] != 0 && !isin; i++) {
        for (int j = 0; in[j] != 0; j++)
            isin = str[i] == str[j] || isin;
    }
    return isin;
}

int str_is_in_arr(char const *str, char **arr, unsigned int nb_arr)
{
    while (nb_arr) {
        if (my_strcmp(str, arr[nb_arr--]) == 0)
            return 1;
    }
    return 0;
}

int int_is_in(int const i, int const *in, ssize_t size)
{
    while (size > 0) {
        if (i == in[size--])
            return 1;
    }
    return 0;
}
