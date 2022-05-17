/*
** EPITECH PROJECT, 2021
** ../lib/wmy
** File description:
** header for ../lib/wmy/
*/

#include "my_types.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

#ifndef WMY_H_
    #define WMY_H_

/* my_wcharsize.c */
ssize_t my_wcharsize(wchar_t wc);

/* my_getwchar.c */
wchar_t my_getwchar(byte_t *cp);

/* my_skipwchar */
wchar_t my_skipwchar(byte_t **cp);

/* my_wwrite */
ssize_t my_wwrite(int fd, wchar_t const *wcbuf, size_t count);

/* my_putwstr.c */
ssize_t my_putwstr(wchar_t const *wstr);
ssize_t my_putwstrarr(wchar_t **wstrarr, wchar_t *sep);

/* my_wstrlen.c */
ssize_t my_wstrlen(wchar_t const *wstr);
ssize_t my_wstrlen_until(wchar_t const *wstr, wchar_t const *seps);

/* my_wstrcmp.c */
int my_wstrcmp(wchar_t const *s1, wchar_t const *s2);
int my_wstrncmp(wchar_t const *s1, wchar_t const *s2, size_t n);

/* my_wstrdup.c */
wchar_t *my_wstrdup(wchar_t const *s);
wchar_t *my_wstrndup(wchar_t const *s, size_t n);

/* my_str_to_wstr.c */
wchar_t *my_str_to_wstr(char const *str);

/* my_wstr_to_array.c */
wchar_t **my_wstr_to_array(wchar_t const *str, wchar_t const *seps);

#endif
