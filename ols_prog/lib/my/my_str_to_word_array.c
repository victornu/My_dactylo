/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** convert a simple char array to an array of word
** of the char array in parameter
*/

#include <stdlib.h>
#include "../../include/my.h"

char **my_str_to_word_array(char const *str)
{
    char **word_array;
    char *seps = malloc(sizeof(char) * 33);
    int len;
    int nb_w = 0;
    int word = 0;

    for (int i = 33; --i >= 0; seps[32 - i] = i);
    for (int i = 0; str[i] != 0; i++)
        if (IS_WORD_START(str, i, IS_TOKEN))
            nb_w++;
    word_array = malloc(sizeof(void *) * (nb_w + 1));
    word_array[nb_w] = NULL;
    for (int i = 0; str[i] != 0 && nb_w > word; i++) {
        while (!IS_WORD_START(str, i, IS_TOKEN) && str[i] != 0 && i++);
        word_array[word] = malloc(ABS_VAL(my_strlen_until(&str[i], seps)) + 1);
        for (len = 0; IS_TOKEN(str[i]); len++)
            word_array[word][len] = str[i++];
        word_array[word++][len] = 0;
    }
    return word_array;
}

char **my_str_to_array(char const *str, char const *seps)
{
    char **word_array;
    int len;
    int nb_w = 0;
    int word = 0;

    for (int i = 0; str[i] != 0; i++)
        if (is_word_start(str, i, seps))
            nb_w++;
    word_array = malloc(sizeof(void *) * (nb_w + 1));
    word_array[nb_w] = NULL;
    for (int i = 0; str[i] != 0 && nb_w > word; i++) {
        while (str[i] != 0 && char_is_in(str[i], seps) && i++);
        len = ABS_VAL(my_strlen_until(&str[i], seps));
        word_array[word] = malloc(sizeof(char) * (len + 1));
        for (int wc = len - 1; wc >= 0; wc--)
            word_array[word][wc] = str[i + wc];
        word_array[word++][len] = 0;
        i += len;
    }
    return word_array;
}
