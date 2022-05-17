//
// Created by vflavien on 2/6/22.
//

#include "include/my.h"
#include "include/wmy.h"
#include "include/fast_finger.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <termios.h>
#include <unistd.h>

void mode_raw(int activer)
{
    static struct termios cooked;
    static int raw_actif = 0;
    struct termios raw;

    if (raw_actif == activer)
        return;
    if (activer) {
        tcgetattr(STDIN_FILENO, &cooked);
        raw = cooked;
        cfmakeraw(&raw);
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    } else
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked);
    raw_actif = activer;
}

wchar_t **get_words(char *file_path)
{
    char *def_fld;
    char *file_buf;
    wchar_t **words;
    struct stat st;
    int fd;

    if (!file_path) {
        def_fld = malloc(CHARSIZE * 21);
        fd = open(my_strcat(my_strcpy(def_fld, WRD_FOLDER), "/default"),
        O_RDONLY);
    } else if (access(file_path, R_OK)) {
        def_fld = malloc(CHARSIZE * 13 * my_strlen(file_path));
        fd = open(my_strcat(my_strcpy(def_fld, WRD_FOLDER), file_path),
        O_RDONLY);
    } else
        fd = open(file_path, O_RDONLY);
    if (fd == -1 || fstat(fd, &st) == -1)
        return NULL;
    file_buf = malloc(CHARSIZE * (st.st_size + 1));
    if (read(fd, file_buf, st.st_size) == -1)
        return NULL;
    words = my_wstr_to_array(my_str_to_wstr(file_buf), my_str_to_wstr("\n"));
    return words;
}

int main(int argc, char **argv)
{
    wchar_t **words = get_words(argv[1]);
    char *buff = malloc(CHARSIZE * 50);
    ssize_t len = 0;

    mode_raw(1);
    my_putstr("-------------------------------\n\r");
        my_putstr("    -    Are you fast?    -    \n\r");
    my_putstr("-------------------------------\n\r");
    for (int t = 0; words[t]; t++) {
        my_putchar('\r');
        display_nexts(&words[t]);
        len = 0;
        for (int i = 0; buff[i]; buff[i++] = 0);
        do {
            read(0, &buff[len], 1);
            display_reads(my_getwchar(&buff[len]), &len, words[t]);
            if (buff[len - 1] == 4 || buff[len - 1] == 13)
                break;
            len >= my_wstrlen(words[t]) && buff[len - 1] != ' ' ? len-- : 0;
        } while (buff[len - 1] != ' ');
        if (buff[len - 1] == 4)
            break;
    }
    free(buff);
    my_putstr("\n\n\n\n\n\n\n\n\r");
    mode_raw(0);
}