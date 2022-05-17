//
// Created by vflavien on 2/8/22.
//

#include "include/wmy.h"

void display_nexts(wchar_t **words)
{
    size_t nb_word = my_wstrarrlen(words);

    nb_word = nb_word >= 8 ? 8 : nb_word;
    my_putstr("\033[J:");
    my_putstr(SGR_LGREY);
    my_putwstr(words[0]);
    my_putstr(SGR_DEFAULT);
    my_putstr("|\n\r[");
    my_putstr(SGR_LBLUE);
    my_putwstr(words[0]);
    my_putstr(SGR_DEFAULT);
    nb_word < 2 ? my_putstr("]") : my_putstr("]\n\r|");
    my_putwstrarr(my_wstrarrndup(words + 1, 7), my_str_to_wstr("\n\r|"));
    while (nb_word++ < 8)
        my_putstr("\n\r|~");
    my_putstr("\033[8F\r:");
}

size_t display_reads(wchar_t key, size_t *n, wchar_t *word)
{
    size_t word_len = my_wstrlen(word);

    if (key == 127) {
        if (*n >= word_len && *n != 0) {
            *n += my_putstr(" ");
        }
        if (*n != 0) {
            my_putstr("\b");
            my_putstr(SGR_LGREY);
            my_wwrite(1, &(word[--(*n)]), 1);
            my_putstr(SGR_DEFAULT);
            my_putchar('\b');
        }
        return 0;
    }
    if (word[*n] == key)
        my_putstr(SGR_LGREEN);
    else
        my_putstr(SGR_LRED);
    *n += my_wwrite(1, &key, 1);
    my_putstr(SGR_DEFAULT);
    if (*n >= word_len)
        my_putchar('\b');
    return 1;
}
