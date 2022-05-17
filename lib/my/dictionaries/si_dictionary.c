/*
** EPITECH PROJECT, 2021
** str_int_dictionary
** File description:
** create, init and destroy string / int dictionary
*/

#include<stdlib.h>
#include "../../../include/my.h"

dsi_t create_dsi(void)
{
    dsi_t dico;

    dico.keys = (void *) 0;
    dico.values = (void *) 0;
    dico.length = 0;
    return dico;
}

dsi_t *new_dsi(void)
{
    dsi_t *dico = malloc(sizeof(dsi_t));

    dico->keys = malloc(sizeof(char *) * 32);
    dico->values = malloc(sizeof(int *) * 32);
    dico->length = 0;
    return dico;
}

void put_elem(dsi_t *dico, char *key, int value)
{
    if (!key)
        return;
    for (int e = 0; e < dico->length; e++) {
        if (!my_strcmp(dico->keys[e], key)) {
            dico->values[e] = value;
            return;
        }
    }
    if ((dico->length + 1) % 32 == 0)
        increase_dsi(dico);
    dico->keys[dico->length] = my_strdup(key);
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

void destroy_dsi(dsi_t *dico)
{
    for (int e = 0; e < dico->length; e++)
        free(dico->keys[e]);
    free(dico->keys);
    free(dico->values);
    free(dico);
}
