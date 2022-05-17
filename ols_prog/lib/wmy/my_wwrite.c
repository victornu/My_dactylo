/*
** EPITECH PROJECT, 2021
** my_wwrite.c
** File description:
** writes up to 'count' bytes from the wchar_t* buffer starting at wcbuf
** to the file referred to by the file descriptor fd.
*/

#include "../../include/wmy.h"

ssize_t my_wwrite(int fd, wchar_t const *wcbuf, size_t count)
{
    ssize_t size = 0;
    ssize_t size_b;
    byte_t *bytes = malloc(sizeof(byte_t) * count * 4);
    ssize_t b = 0;

    for (unsigned int wc = 0; wc < count; wc++) {
        size_b = my_wcharsize(wcbuf[wc]);
        size += size_b;
        for (int c = size_b - 1; c >= 0; c--)
            bytes[b++] = wcbuf[wc] >> (8 * c);
    }
    size = write(fd, bytes, size);
    free(bytes);
    return size;
}
