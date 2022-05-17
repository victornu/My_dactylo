/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** put a character
*/

#include <unistd.h>

ssize_t my_putchar(char const c)
{
    return write(1, &c, 1);
}

ssize_t my_putchar_to(char const c, int fd)
{
    return write(fd, &c, 1);
}
