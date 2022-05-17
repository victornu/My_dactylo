/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** convert a simple char array to an array of word
** of the char array in parameter
*/

#include <stdlib.h>
#include "../../../include/my.h"

char **my_strtok(char const *str, char const *seps)
{
    char **word_array;
    int nb_w = 0;
    int w = 0;

    for (int i = 0; str && seps && str[i] != 0; i++)
        if (is_word_start(str, i, seps))
            nb_w++;
    word_array = malloc(sizeof(void *) * (nb_w + 1));
    if (!str || !seps || !word_array)
        return NULL;
    word_array[nb_w] = NULL;
    for (int i = 0; str[i] != 0 && nb_w > w; i++) {
        while (str[i] && char_is_in(str[i], seps) && ++i);
        word_array[w++] = my_strndup(&str[i], my_strcspn(&str[i], seps));
        if (!word_array[w - 1])
            return free_strarr(word_array) ? NULL : NULL;
        i += my_strlen(word_array[w - 1]) - 1;
    }
    return word_array;
}
