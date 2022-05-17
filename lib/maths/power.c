/*
** EPITECH PROJECT, 2021
** power.c
** File description:
** power a number
*/

long double power(double x, int n)
{
    long double power;
    _Bool negative_power = n < 0;

    if (n == 0)
        return 1;
    else if (negative_power)
        n = -n;
    power = x;
    while (n > 1) {
        power *= x;
        n--;
    }
    if (negative_power)
        power = 1 / power;
    return power;
}
