/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my printf
*/

#include "../../../include/my.h"
#include <unistd.h>
#include <stdarg.h>

int my_printf(char const *format, ...)
{
    va_list vars;
    size_t tmp_size;
    size_t prnt_size = 0;

    va_start(vars, format);
    while (*format != 0) {
        tmp_size = ABS_VAL(my_strlen_until(format, "%"));
        write(1, format, tmp_size);
        prnt_size += tmp_size;
        format += tmp_size;
        if (*format != '%')
            write(1, format, 1);
        else
            prnt_size += put_identifiers(&format, vars);
    }
    return prnt_size;
}
