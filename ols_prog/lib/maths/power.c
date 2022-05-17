/*
** EPITECH PROJECT, 2021
** power.c
** File description:
** power a number
*/

int power(int x, int n)
{
    int power;

    if (n <= 0)
        return n == 0;
    power = x;
    while (n > 1) {
        power *= x;
        n--;
    }
    return power;
}

int rec_power(int x, int n)
{
    return n > 0 ? (x * rec_power(x, n - 1)) : n == 0;
}
