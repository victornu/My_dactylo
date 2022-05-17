/*
** EPITECH PROJECT, 2021
** my_types
** File description:
** header for my custom types and macros
*/

#ifndef MY_TYPES_H_
    #define MY_TYPES_H_

    #define CHARSIZE sizeof(char)
    #define MINCHAR -128
    #define MAXCHAR 127
    #define MAXUCHAR 255

    #define SHORTSIZE sizeof(short)
    #define MINSHORT -32758
    #define MAXSHORT 32767
    #define MAXUSHORT 65535

    #define INTSIZE sizeof(int)
    #define MININT -2147483648
    #define MAXINT 2147483647
    #define MAXUINT 4294967295

    #define LONGSIZE sizeof(long)
    #define MINLONG -9223372036854775808
    #define MAXLONG 9223372036854775807
    #define MAXULONG 18446744073709551615ULL

    #define DBLSIZE sizeof(double)
    #define MINFLT 1.175494351e-38F
    #define MAXFLT 3.402823466e+38F

    #define DBLSIZE sizeof(double)
    #define MINDBL 2.2250738585072014e-308
    #define MAXDBL 1.7976931348623158e+308

    #define STR_MINCHAR "-128"
    #define STR_MAXCHAR "127"
    #define STR_MAXUCHAR "255"

    #define STR_MINSHORT "-32758"
    #define STR_MAXSHORT "32767"
    #define STR_MAXUSHORT "65535"

    #define STR_MININT "-2147483648"
    #define STR_MAXINT "2147483647"
    #define STR_MAXUINT "4294967295"

    #define STR_MINLONG "-9223372036854775808"
    #define STR_MAXLONG "9223372036854775807"
    #define STR_MAXULONG "18446744073709551615"

    #define BIN_BASE "01"
    #define OCT_BASE "01234567"
    #define DEC_BASE "0123456789"
    #define L_HEX_BASE "0123456789abcdef"
    #define U_HEX_BASE "0123456789ABCDEF"

/* smallest type */
typedef unsigned char byte_t;
typedef signed char tcc_t;

/* biggest types */
typedef unsigned long long int _8byte_t;
typedef signed long long int tcc8_t;

/* infin number array types */
typedef unsigned char *numa_t;
typedef unsigned const char numb_t[];
// 256 possible digits

typedef unsigned short *num2a_t;
typedef unsigned const short num2b_t[];
// 65536 possible digits

#endif
