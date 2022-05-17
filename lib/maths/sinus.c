/*
** EPITECH PROJECT, 2021
** sinus.c
** File description:
** do sinus func on a number
*/

#include "../../include/maths.h"

double sinus(double x, short n_iteration)
{
    double sin_x = 0;

    x -= ((int)(x / (2 * PI))) * 2 * PI;
    for (int co = 0; co < n_iteration; co++) {
        if (co & 1)
            sin_x -= (power(x, co * 2 + 1) / factorial(co * 2 + 1));
        else
            sin_x += (power(x, co * 2 + 1) / factorial(co * 2 + 1));
    }
    return sin_x;
}

double my_sin(double x)
{
    double sin_x = 0;
    const double coeffs[11] = {1, -0.16666666666666666666666666666666,
        0.00833333333333333333333333333333, -0.0001984126984126984126984126984,
        0.00000275573192239858906525573192, -0.0000000250521083854417187750521,
        0.00000000016059043836821614599392, -0.0000000000007647163731819816476,
        0.00000000000000281145725434552076, -0.0000000000000000082206352466243,
        0.00000000000000000001957294106339};

    x -= ((int)(x / (2 * PI))) * 2 * PI;
    for (int co = 0; co < 11; co++)
        sin_x += (coeffs[co] * power(x, co * 2 + 1));
    return sin_x;
}
