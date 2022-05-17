/*
** EPITECH PROJECT, 2021
** str_int_dictionary
** File description:
** transform number to char array
*/

#include "../../include/my.h"

byte_t elem_exists(dsi_t *dico, char const *key)
{
    if (dico == NULL || key == NULL)
        return -1;
    for (int e = 0; e < dico->length; e++) {
        if (my_strcmp(dico->keys[e], key) == 0)
            return 1;
    }
    return 0;
}

int get_from_key(dsi_t *dico, char const *key)
{
    if (dico == NULL || key == NULL)
        return -1;
    for (int val = 0; val < dico->length; val++) {
        if (my_strcmp(dico->keys[val], key) == 0)
            return dico->values[val];
    }
    return 0;
}

char *get_from_val(dsi_t *dico, int const value)
{
    if (dico == NULL)
        return NULL;
    for (int key = 0; key < dico->length; key++) {
        if (dico->values[key] == value)
            return dico->keys[key];
    }
    return (void *) 0;
}
