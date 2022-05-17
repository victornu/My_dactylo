/*
** EPITECH PROJECT, 2021
** cosinus.c
** File description:
** do cosinus func on a number
*/

#include "../../include/maths.h"

double cosinus(double x, short n_iteration)
{
    double cos_x = 0;

    x -= ((int)(x / (2 * PI))) * 2 * PI;
    for (int co = 0; co < n_iteration; co++) {
        if (co & 1)
            cos_x -= (power(x, co * 2) / factorial(co * 2));
        else
            cos_x += (power(x, co * 2) / factorial(co * 2));
    }
    return cos_x;
}

double my_cos(double x)
{
    double cos_x = 0;
    const double coeffs[16] = {1, -0.5, 0.04166666666666666666666666666666,
        -0.00138888888888888894189432843262, 0.0000248015873015873015657896394,
        -0.00000027557319223985888275785857, 0.0000000020876756987868100186555,
        -0.00000000001147074559772972450730, 0.0000000000000477947733238738525,
        -0.0000000000000001561920696858623, 0.0000000000000000004110317623312};

    x -= ((int)(x / (2 * PI))) * 2 * PI;
    for (int co = 0; co < 11; co++)
        cos_x += (coeffs[co] * power(x, co * 2));
    return cos_x;
}
