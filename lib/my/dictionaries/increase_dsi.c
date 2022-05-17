/*
** EPITECH PROJECT, 2021
** str_int_dictionary
** File description:
** increase the number of possible dsi elements
*/

#include<stdlib.h>
#include "../../../include/my.h"

void increase_dsi(dsi_t *dico)
{
    char **keys_buffer = malloc(sizeof(char *) * (dico->length + 32));
    int *values_buffer = malloc(sizeof(int *) * (dico->length + 32));

    for (int e = 0; e < dico->length; e++) {
        keys_buffer[e] = dico->keys[e];
        values_buffer[e] = dico->values[e];
    }
    free(dico->keys);
    free(dico->values);
    dico->keys = malloc(sizeof(char *) * dico->length * 32);
    dico->values = malloc(dico->length + sizeof(int *) * 32);
    for (int e = 0; e < dico->length; e++) {
        dico->keys[e] = keys_buffer[e];
        dico->values[e] = values_buffer[e];
    }
    free(keys_buffer);
    free(values_buffer);
}
