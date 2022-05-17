/*
** EPITECH PROJECT, 2021
** exponential.c
** File description:
** do exponential func on a number
*/

#include "../../include/maths.h"

double exponential(double x, short n_iteration)
{
    double exp_x = 0;

    for (int co = 0; co < n_iteration; co++)
        exp_x += (power(x, co) / factorial(co));
    return exp_x;
}

double my_exp(double x)
{
    double exp_x = x;

    const double coeffs[11] = {1, 1, 0.5,
        0.16666666666666666666666666666667, 0.04166666666666666666666666666667,
        0.00833333333333333333333333333333, 0.00138888888888888888888888888889,
        0.00019841269841269841252631711548, 0.00002480158730158730156578963943,
        0.00000275573192239858925109505933, 0.00000027557319223985888275785857
    };
    for (int co = 0; co < 11; co++)
        exp_x += coeffs[co] * (power(x, co));
    return exp_x;
}
