/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** handle variable
*/

#include "../../../include/my.h"
#include <stdlib.h>

void cast_var(_8byte_t *var, char const *flag, int id_len)
{
    if (char_is_in(flag[id_len - 2], LEN_MODIFIER)
        && !char_is_in(flag[id_len - 3], LEN_MODIFIER)) {
        *var = (flag[id_len - 2] == 'h' ? (short) *var : (long) *var);
    } else if (char_is_in(flag[id_len - 2], DBL_MODIFIER)
    && flag[id_len - 3] == flag[id_len - 2])
        *var = (flag[id_len - 2] == 'h' ? (char) *var : (long long) *var);
    if (!char_is_in(flag[id_len - 2], LEN_MODIFIER)) {
        if (char_is_in(flag[id_len - 1], "uoxXp"))
            *var = (unsigned int) *var;
        else
            *var = (int) *var;
    }
}

size_t get_var_size(_8byte_t *var, char const *flag, int id_len)
{
    size_t prnt_size = 0;

    if (char_is_in(flag[id_len - 1], "boxXp")) {
        prnt_size += flag[id_len - 1] == 'o' ?
        my_nbr_base_len(*var, OCT_BASE) : my_nbr_base_len(*var, L_HEX_BASE);
    } else if (char_is_in(flag[id_len - 1], "diu"))
        prnt_size += my_longlen(*var);
    if (char_is_in(flag[id_len - 1], "sS"))
        prnt_size += my_strlen((char *) var);
    return prnt_size;
}

size_t conv_and_put(_8byte_t n, char const conv_spec)
{
    switch (conv_spec) {
        case 'b':
            my_putulnbr_base(n, BIN_BASE);
            return my_nbr_base_len(n, BIN_BASE);
        case 'o':
            my_putulnbr_base(n, OCT_BASE);
            return my_nbr_base_len(n, OCT_BASE);
        case 'X':
            my_putulnbr_base(n, U_HEX_BASE);
            return my_nbr_base_len(n, U_HEX_BASE);
        case 'x':
        case 'p':
            my_putulnbr_base(n, L_HEX_BASE);
            return my_nbr_base_len(n, L_HEX_BASE);
        case 'u':
            my_putulong(n);
            return my_ulonglen(n);
    }
    my_putlong(n);
    return my_longlen(n);
}

size_t put_var(_8byte_t var, size_t var_len, char const *flag, size_t id_len)
{
    char *fls;
    byte_t unsign = 0;
    size_t prnt_size = 0;
    size_t flags_len;

    for (flags_len = 1; char_is_in(flag[flags_len], FLAGS); flags_len++);
    fls = malloc(flags_len);
    my_strncpy(fls, flag + 1, flags_len - 1);
    if ((char_is_in('#', fls) && char_is_in(flag[id_len - 1], "boxX"))
    || flag[id_len - 1] == 'p') {
        prnt_size += my_putchar('0');
        if (flag[id_len - 1] != 'o')
            prnt_size += flag[id_len - 1] == 'p' ? my_putchar(flag[id_len - 1])
            : my_putchar('x');
    }
    if (flag[id_len - 1] == 's')
        prnt_size += my_putstr((char *) var);
    if (char_is_in(flag[id_len - 1], NUM_SPEC))
        prnt_size += conv_and_put(var, flag[id_len - 1]);
    return prnt_size;
}
