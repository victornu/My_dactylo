/*
** EPITECH PROJECT, 2021
** my_wstr_to_array.c
** File description:
** convert a wchar_t array 'wstr' to an array of word
** separated by one or more wchar_t in array 'seps'
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/wmy.h"

wchar_t **my_wstr_to_array(wchar_t const *wstr, wchar_t const *seps)
{
    wchar_t **word_array;
    int len;
    int nb_w = 0;
    int word = 0;

    for (int i = 0; wstr[i] != 0; i++)
        if (is_wide_word_start(wstr, i, seps))
            nb_w++;
    word_array = malloc(sizeof(void *) * (nb_w + 1));
    word_array[nb_w] = NULL;
    for (int i = 0; wstr[i] != 0 && nb_w > word; i++) {
        while (wstr[i] != 0 && wchar_is_in(wstr[i], seps) && i++);
        len = ABS_VAL(my_wstrlen_until(&wstr[i], seps));
        word_array[word] = malloc(sizeof(wchar_t) * (len + 1));
        for (int wc = len - 1; wc >= 0; wc--)
            word_array[word][wc] = wstr[i + wc];
        word_array[word++][len] = 0;
        i += len;
    }
    return word_array;
}
