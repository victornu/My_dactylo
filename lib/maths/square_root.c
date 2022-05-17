/*
** EPITECH PROJECT, 2021
** square_root.c
** File description:
** square a number
*/

double square_root(double x, double epsilon)
{
    double square_x = x;

    while (square_x - x / square_x > epsilon)
        square_x = (square_x + x / square_x) / 2;
    return square_x;
}

float my_sqrt(float x)
{
    float square_x = x;

    while (square_x - x / square_x > 0.00001)
        square_x = (square_x + x / square_x) / 2;
    return square_x;
}
