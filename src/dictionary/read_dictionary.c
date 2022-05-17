/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** read dictionary content into 'char *' buffer
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <inttypes.h>
#include "../../include/my.h"
#include "../../include/fast_finger.h"

int handle_read_errors(int status)
{
    status == -1 ? write(2, "\rCannot read selected dictionary\n\r", 34) : 0;
    status == -2 ? write(2, "\rSelected dictionary doesn't exist\n\r", 36): 0;
    status >= 0 ? write(2, "\rCannot get dictionary file stats\n\r", 35) : 0;
    return 0;
}

char *read_dictionary(char *dic_name)
{
    char *path = my_strcat(my_strndup(
    DICTIONARIES_PATH, 14 + my_strlen(dic_name)), dic_name);
    int fd = access(path, F_OK) ? -2 : open(path, O_RDONLY);
    struct stat dic_st;
    char *dictionary;
    size_t size;

    if (fd == -2 || stat(path, &dic_st) == -1)
        return (void *)(intptr_t)handle_read_errors(fd);
    free(path);
    dictionary = malloc(sizeof(char) * (dic_st.st_size + 1));
    size = read(fd, dictionary, dic_st.st_size);
    if (size == -1) {
        write(2, "\rCannot read selected dictionary\n\r", 31);
        free(dictionary);
        return NULL;
    }
    dictionary[size] = 0;
    return dictionary;
}
