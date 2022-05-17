/*
** EPITECH PROJECT, 2021
** ../lib/my
** File description:
** header for ../lib/my/
*/

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_types.h"

#ifndef MY_H_
    #define MY_H_

    #define SGR_DEFAULT "\033[0;0m"

    #define SGR_BLACK "\033[0;30m"
    #define SGR_RED "\033[0;31m"
    #define SGR_GREEN "\033[0;32m"
    #define SGR_ORANGE "\033[0;33m"
    #define SGR_BLUE "\033[0;34m"
    #define SGR_PURPLE "\033[0;35m"
    #define SGR_CYAN "\033[0;36m"
    #define SGR_LGREY "\033[0;37m"
    #define SGR_DGREY "\033[1;30m"
    #define SGR_LRED "\033[1;31m"
    #define SGR_LGREEN "\033[1;32m"
    #define SGR_YELLOW "\033[1;33m"
    #define SGR_LBLUE "\033[1;34m"
    #define SGR_LPURPLE "\033[1;35m"
    #define SGR_LCYAN "\033[1;36m"
    #define SGR_WHITE "\033[1;37m"

    #define IS_NEG(n) ((n) < 0)
    #define ABS_VAL(n) ((n) < 0 ? -(n) : (n))
    #define IS_PRINTABLE(c) ((c) >= ' ' && (c) < 127)
    #define IS_TOKEN(c) ((c) > ' ' && (c) < 127)
    #define IS_NUM(c) ((c) >= '0' && (c) <= '9')
    #define IS_ALPHA(c) \
    (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
    #define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')
    #define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')
    #define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUM(c))

    #define IS_ADDS_OP(c) ((c) == '+' || (c) == '-')
    #define IS_FACS_OP(c) ((c) == '*' || (c) == '/' || (c) == '%')
    #define IS_OP(c) (IS_BASIC_OP(c) || IS_PRIO_OP)

    #define IS_WORD_START(s, i, sep_cond) \
    (sep_cond((s)[i]) && (i == 0 || !sep_cond((s)[i - 1])))
    #define IS_WORD_END(s, i, sep_cond) \
    (!sep_cond((s)[i]) && (i != 0 && sep_cond((s)[i - 1])))

    #define HTML_ASCII_PUNC "!#%&()*,-./:;?[\\]^_`{|}~"

/* my_printf */
    #define FLAGS "#0- +"
    #define LEN_MODIFIER "hlq"
    #define DBL_MODIFIER "hl"
    #define CONV_SPECIFIERS "dibouxXcsSp%"
    #define NUM_SPEC "dibouxXp"

int my_printf(char const *format, ...);
size_t put_identifiers(char const **flag, va_list vars);
size_t get_identifiers_len(char const *flag);
void cast_var(_8byte_t *var, char const *flag, int id_len);
size_t get_var_size(_8byte_t *var, char const *flag, int id_len);
size_t put_var(_8byte_t var, size_t var_len, char const *flag, size_t id_len);

/* my_setalloc.c */
void *my_setalloc(void **buf, size_t size, byte_t set);

/* my_memset.c */
void *my_memset(void *s, int const c, size_t n);

/* my_memmove.c */
void *my_memmove(void *dest, const void *src, size_t n);

/* free_ptrarr.c */
size_t free_in_arr(void **array);
size_t free_strarr(char **strarr);

/* my_putchar */
ssize_t my_putchar(char const c);
ssize_t my_putchar_to(char const c, int fd);

/* my_putstr.c */
ssize_t my_putstr(char const *str);
ssize_t my_putstr_to(char const *str, int fd);
long my_putstr_all(char const *str);
ssize_t my_putstrarr(char **strarr, char *sep);

/* my_putnbr.c */
byte_t my_putnbr_to(long nb, int fd);
byte_t my_putint(int nb);
byte_t my_putuint(unsigned int nb);
byte_t my_putlong(long nb);
byte_t my_putulong(unsigned long nb);

/* my_nblen.c */
byte_t my_nblen(long nb);
byte_t my_intlen(int nb);
byte_t my_uintlen(unsigned int nb);
byte_t my_longlen(long nb);
byte_t my_ulonglen(unsigned long nb);

/* ntoa.c */
char *itoa(int i);
char *uitoa(unsigned int i);
char *ltoa(long i);
char *ultoa(unsigned long i);

/* my_getnbr.c */
long my_getnbr(char const *str);
int my_getint(char const *str);
unsigned int my_getuint(char const *str);
long my_getlong(char const *str);
unsigned long my_getulong(char const *str);

/* skipget_nbr.c */
long skipget_nbr(char *str);
int skipget_int(char **strptr);
unsigned int skipget_uint(char **strptr);
long skipget_long(char **strptr);
unsigned long skipget_ulong(char **strptr);

/* my_strlen.c */
ssize_t my_strlen(char const *str);
short my_strshortlen(char const *str);
long my_strlonglen(char const *str);
ssize_t my_strlen_until(char const *str, char const *seps);
ssize_t my_strarrlen(char **starr);

/* my_strcpy.c */
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t n);

/* my_strcmp.c */
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t n);

/* my_strspn.c */
size_t my_strspn(char const *s, char const *accept);
size_t my_strcspn(char const *s, char const *reject);

/* my_strstr.c */
const char *my_strstr(const char *haystack, const char *needle);
char **my_strarrstrarr(char **haystack, const char *needle);

/* my_strdup.c */
char *my_strdup(char const *s);
char *my_strndup(char const *s, size_t n);
char **my_strarrdup(char **strarr);

/* my_strcat.c */
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, size_t n);

/* my_revstr.c */
char *my_revstr(char *str);

/* my_str_is_nb.c */
byte_t my_str_is_int(char *str);
byte_t my_str_is_uint(char *str);

/* word_tools.c */
int is_word_start(char const *str, int i, char const *seps);
int is_word_end(char const *str, int i, char const *seps);
int is_wide_word_start(wchar_t const *str, int i, wchar_t const *seps);

/* my_strtok.c */
char **my_strtok(char const *str, char const *seps);

/* is_in */
int char_is_in(char const c, char const *in);
int wchar_is_in(wchar_t const c, wchar_t const *in);
int in_str_is_in(char const *str, char const *in);
int str_is_in_arr(char const *str, char **arr, unsigned int nb_arr);
int int_is_in(int const i, int const *in, ssize_t size);

/* my_putnbr_base.c */
int my_putnbr_base(int nbr, char const *base);
int my_putlnbr_base(long nbr, char const *base);
int my_putulnbr_base(unsigned long nbr, char const *base);

/* my_getnbr_base.c */
int my_getnbr_base(char const *str, char const *base);

/* my_nbr_base_len.c */
size_t my_nbr_base_len(long nbr, char const *base);

/* base_converter */
byte_t get_val_of_base(byte_t numeral, numb_t base);
numa_t convert_to(numa_t number, numb_t origin_base, numb_t dest_base);

/* my_transform_str.c */
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);

typedef struct dictionary_str_int {
    char **keys;
    int *values;
    int length;
} dsi_t;

/* si_dictionary.c */
dsi_t create_dsi(void);
dsi_t *new_dsi(void);
void put_elem(dsi_t *dico, char *key, int value);
tcc_t del_elem(dsi_t *dico, char *key);
void destroy_dsi(dsi_t *dico);

/* increase_dsi.c */
void increase_dsi(dsi_t *dico);

/* get_si_dic.c */
byte_t elem_exists(dsi_t *dico, char const *key);
int get_from_key(dsi_t *dico, char const *key);
char *get_from_val(dsi_t *dico, int const value);

#endif
