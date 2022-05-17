/*
** EPITECH PROJECT, 2021
** FastFinger
** File description:
** display headers of program
*/

#include <unistd.h>

void display_launch_header(void)
{
    char header[] = "\r-----------------------------------\n"
                    "\r    -   Fast Finger Tester    -    \n"
                    "\r-----------------------------------\n\n\r";
    write(1, header, 113);
}

void display_selection_header(void)
{
    char header[] = "\rPlease choose which dictionary to use: \n\r";

    write(1, header, 42);
}

void display_begin_header(void)
{
    char header[] = "\r-------------------------------\n"
                    "\r    -    Are you fast?    -    \n"
                    "\r-------------------------------\n\r";

    write(1, header, 100);
}
