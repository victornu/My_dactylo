/*
** EPITECH PROJECT, 2021
** my_strspn.c
** File description:
** my strspn
*/

#include "../../../include/my.h"

size_t my_strspn(char const *s, char const *accept)
{
    size_t size = 0;

    if (!s || !accept)
        return 0;
    while (s[size] && char_is_in(s[size], accept))
        size++;
    return size;
}

size_t my_strcspn(char const *s, char const *reject)
{
    size_t size = 0;

    if (!s || !reject)
        return 0;
    while (s[size] && !char_is_in(s[size], reject))
        size++;
    return size;
}
