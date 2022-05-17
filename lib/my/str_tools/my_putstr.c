/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** write a char array
*/

#include <unistd.h>
#include "../../../include/my.h"

ssize_t my_putstr(char const *str)
{
    unsigned long len;

    if (str == 0)
        return -1;
    for (len = 0; str[len] != 0; len++);
    return write(1, str, len);
}

ssize_t my_putstr_to(char const *str, int fd)
{
    unsigned long len;

    if (str == 0)
        return -1;
    for (len = 0; str[len] != 0; len++);
    return write(fd, str, len);
}

long my_putstr_all(char const *str)
{
    char *non_prt;
    long len = 2;

    if (str == 0)
        return -1;
    for (unsigned long i = 0; str[i] != 0; i++) {
        if ((str[i] >= 0 && str[i] < 32) || str[i] == 127) {
            non_prt = itoa(str[i]);
            write(1, "\\000", 4 - my_strlen(non_prt));
            write(1, non_prt, my_strlen(non_prt));
            len += 4;
        }
        write(1, &str[i], 1);
        len++;
    }
    write(1, "\\0", 2);
    return len;
}

ssize_t my_putstrarr(char **strarr, char *sep)
{
    ssize_t size = 0;
    ssize_t s_buff;

    if (strarr == NULL || sep == 0)
        return -1;
    while (*strarr) {
        s_buff = my_putstr(*strarr++);
        size += s_buff > 0 ? s_buff : 0;
        if (*strarr != NULL) {
            s_buff = my_putstr(sep);
            size += s_buff > 0 ? s_buff : 0;
        }
    }
    return size;
}
