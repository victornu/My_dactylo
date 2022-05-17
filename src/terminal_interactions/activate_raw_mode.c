/*
** EPITECH PROJECT, 2021
** FastFinger
** File description:
** activate/set raw mode or unset/reset current user terminal
*/

#include <termios.h>
#include <unistd.h>

void activate_row_mode(int activate)
{
    static struct termios cooked;
    static int already_activated = 0;
    struct termios raw;

    if (already_activated == activate)
        return;
    if (activate) {
        tcgetattr(STDIN_FILENO, &cooked);
        raw = cooked;
        cfmakeraw(&raw);
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    } else
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked);
    already_activated = activate;
}
