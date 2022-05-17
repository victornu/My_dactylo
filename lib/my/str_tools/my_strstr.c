/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** my strstr
*/

#include "../../../include/my.h"

const char *my_strstr(const char *haystack, const char *needle)
{
    int len = my_strlen(needle);

    if (haystack == NULL)
        return NULL;
    while (*haystack != 0) {
        if (!my_strncmp(haystack, needle, len))
            return haystack;
        haystack++;
    }
    return NULL;
}

char **my_strarrstrarr(char **haystack, const char *needle)
{
    if (haystack == NULL || needle == NULL)
        return NULL;
    while (*haystack) {
        if (!my_strcmp(*haystack, needle))
            return haystack;
        haystack++;
    }
    return NULL;
}
