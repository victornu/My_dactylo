/*
** EPITECH PROJECT, 2021
** str_int_dictionary
** File description:
** transform number to char array
*/

#include<stdlib.h>
#include "../../include/my.h"

dsi_t create_si_dic(void)
{
    dsi_t dico;

    dico.keys = (void *) 0;
    dico.values = (void *) 0;
    dico.length = 0;
    return dico;
}

dsi_t *new_si_dic(void)
{
    dsi_t *dico = malloc(sizeof(dsi_t));

    dico->keys = malloc(sizeof(void *) * 32);
    dico->values = malloc(sizeof(void *) * 32);
    dico->length = 0;
    return dico;
}

void increase_si_dic(dsi_t *dico)
{
    char **keys_buffer = malloc(sizeof(void *) * 32);
    int *values_buffer = malloc(sizeof(void *) * 32);

    for (int e = 0; e < dico->length; e++) {
        keys_buffer[e] = dico->keys[e];
        values_buffer[e] = dico->values[e];
    }
    free(dico->keys);
    free(dico->values);
    dico->keys = malloc(dico->length + sizeof(void *) * 32);
    dico->values = malloc(dico->length + sizeof(void *) * 32);
    for (int e = 0; e < dico->length; e++) {
        dico->keys[e] = keys_buffer[e];
        dico->values[e] = values_buffer[e];
    }
}

void put_elem(dsi_t *dico, char *key, int value)
{
    for (int e = 0; e < dico->length; e++) {
        if (my_strcmp(dico->keys[e], key) == 0) {
            dico->values[e] = value;
            return;
        }
    }
    if (dico->length / 32 > 0)
        increase_si_dic(dico);
    dico->keys[dico->length] = key;
    dico->values[dico->length++] = value;
}

tcc_t del_elem(dsi_t *dico, char *key)
{
    int e;

    if (dico == NULL || key == NULL)
        return -1;
    for (e = 0; my_strcmp(dico->keys[e], key) != 0 && e < dico->length; e++);
    if (e == dico->length)
        return 0;
    my_memmove(&dico->keys[e], &dico->keys[e + 1],
    sizeof(char *) * (dico->length - e));
    dico->length--;
    return 1;
}
