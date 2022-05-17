/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int len;
    char buffer;

    for (len = 0; str[len] != 0; len++);
    for (int i = 0; i < len / 2; i++){
        buffer = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = buffer;
    }
    return str;
}
