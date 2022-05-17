/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** return dictionaries files name
*/

#include "../../include/my.h"
#include "../../include/fast_finger.h"
#include <stdlib.h>
#include <dirent.h>

ssize_t get_number_of_dictionaries(void)
{
    DIR *dir;
    struct dirent *dir_comp;
    size_t n_sub = 0;

    dir = opendir(DICTIONARIES_PATH);
    if (!dir)
        return -1;
    dir_comp = readdir(dir);
    while (dir_comp != NULL) {
        n_sub += my_strcmp(dir_comp->d_name, ".")
        && my_strcmp(dir_comp->d_name, "..");
        dir_comp = readdir(dir);
    }
    closedir(dir);
    return n_sub;
}

char **get_dictionaries_name(void)
{
    char **subfiles;
    struct dirent *dir;
    DIR *curr_dir;
    ssize_t n_sub = get_number_of_dictionaries();

    curr_dir = n_sub != -1 ? opendir(DICTIONARIES_PATH) : NULL;
    subfiles = curr_dir ? malloc(sizeof(char *) * (n_sub + 1)) : NULL;
    (!subfiles && curr_dir) ? closedir(curr_dir) : 0;
    if (!subfiles)
        return NULL;
    dir = readdir(curr_dir);
    for (n_sub = 0; dir != 0; ) {
        if (my_strcmp(dir->d_name, ".") && my_strcmp(dir->d_name, ".."))
            subfiles[n_sub++] = my_strdup(dir->d_name);
        dir = readdir(curr_dir);
    }
    subfiles[n_sub] = NULL;
    closedir(curr_dir);
    return subfiles;
}
