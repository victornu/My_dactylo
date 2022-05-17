/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** handle identifiers
*/

#include "../../../include/my.h"
#include <stdarg.h>
#include <stdlib.h>

size_t get_identifiers_len(char const *flag)
{
    size_t size = 0;

    if (*flag == '%')
        size++;
    else
        return 0;
    for ( ; char_is_in(flag[size], FLAGS); size++);
    for ( ; IS_NUM(flag[size]); size++);
    if (flag[size] == '.')
        size++;
    for ( ; IS_NUM(flag[size]); size++);
    if (char_is_in(flag[size], LEN_MODIFIER)) {
        size++;
        if (char_is_in(flag[size], DBL_MODIFIER))
            size += flag[size] == flag[size - 1];
    }
    if (char_is_in(flag[size], CONV_SPECIFIERS))
        size++;
    return size;
}

size_t handle_identifier(char const **flag, char const conv_spec, size_t n_id)
{
    size_t prnt_size = 0;

    if (!conv_spec || conv_spec == '%') {
        prnt_size += write(1, (*flag)++, 1);
        for (unsigned int n = 1; char_is_in(**flag,FLAGS)
        && n <= n_id; n++) {
            prnt_size += write(1, (*flag)++, 1);
        }
        *flag += n_id - prnt_size;
        return prnt_size;
    }
    return prnt_size;
}

size_t put_identifiers(char const **flag, va_list vars)
{
    size_t n_id = get_identifiers_len(*flag);
    char const conv_spec = char_is_in((*flag)[n_id - 1], CONV_SPECIFIERS)
    ? (*flag)[n_id - 1] : 0;
    size_t prnt_size = handle_identifier(flag, conv_spec, n_id);
    _8byte_t var;
    size_t var_l;

    if (prnt_size)
        return prnt_size;
    var = va_arg(vars, long);
    cast_var(&var, *flag, n_id);
    var_l = conv_spec != 'c' ? get_var_size(&var, *flag, n_id) : 1;
    prnt_size += put_var(var, var_l, *flag, n_id);
    *flag += n_id;
    return prnt_size;
}
