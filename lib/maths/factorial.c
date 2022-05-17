/*
** EPITECH PROJECT, 2021
** factorial.c
** File description:
** factorial a number
*/

double factorial(unsigned int x)
{
    double fac_x = 1;

    while (x)
        fac_x *= x--;
    return fac_x;
}
