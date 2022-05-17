/*
** EPITECH PROJECT, 2021
** my_wstrcmp.c
** File description:
** compare wchar_t strings
*/

#include <stdlib.h>

int my_wstrcmp(wchar_t const *s1, wchar_t const *s2)
{
    size_t len1;
    size_t len2;
    unsigned int i;

    for (len1 = 0; s1[len1] != 0; len1++);
    for (len2 = 0; s2[len2] != 0; len2++);
    if (len1 != len2)
        return len1 - len2 > 0 ? 1 : -1;
    for (i = 0; s1[i] != 0 && s2[i] != 0; i++){
        if (s1[i] != s2[i])
            return (s1[i] - s2[i] > 0 ? 1 : -1);
    }
    if (s1[i] != s2[i])
        return (s1[i] - s2[i] > 0 ? 1 : -1);
    return 0;
}

int my_wstrncmp(wchar_t const *s1, wchar_t const *s2, size_t n)
{
    unsigned int i;

    for (i = 0; s1[i] != 0 && s2[i] != 0 && i < n; i++){
        if (s1[i] != s2[i])
            return (s1[i] - s2[i] > 0 ? 1 : -1);
    }
    return 0;
}
