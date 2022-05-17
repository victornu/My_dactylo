/*
** EPITECH PROJECT, 2021
** tangent.c
** File description:
** do tangent func on a number
*/

#include "../../include/maths.h"

double tangent(double x, short n_iteration)
{
    return sinus(x, n_iteration) / cosinus(x, n_iteration);
}

double my_tan(double x)
{
    return my_sin(x) / my_cos(x);
}
