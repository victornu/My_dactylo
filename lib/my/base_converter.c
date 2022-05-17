/*
** EPITECH PROJECT, 2021
** base_converter.c
** File description:
** convert a number in a other base
*/

#include "../../include/my.h"
#include "../../include/maths.h"
#include <stdlib.h>

byte_t get_val_of_base(byte_t numeral, numb_t base)
{
    byte_t val;

    for (val = 0; numeral != base[val] && base[val] != 0; val++);
    return base[val] != 0 ? val : -1;
}

numa_t convert_to(numa_t number, numb_t origin_base, numb_t dest_base)
{
    long o_len = my_strlen((char *) origin_base);
    long d_len = my_strlen((char *) dest_base);
    long upper_len = o_len > d_len ? o_len : d_len;
    long num_len = my_strlen((char *) number);
    numa_t convert;
    int p;
    long dec_val = 0;

    for (p = 0; power(o_len + d_len - upper_len, p) < upper_len; p++);
    convert = malloc(upper_len * p);
    for (long n = 0; n < num_len; n++) {
        dec_val += get_val_of_base(number[num_len - n - 1],
        origin_base) * power(o_len, n);
    }
    for (long n = 0; dec_val > 0; n++) {
        convert[n] = dest_base[dec_val % d_len];
        dec_val /= d_len;
    }
    my_revstr((char *) convert);
    return convert;
}
