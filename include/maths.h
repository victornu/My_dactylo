/*
** EPITECH PROJECT, 2021
** ../lib/maths
** File description:
** header for ../lib/maths/
*/

#ifndef MATHS_H_
    #define MATHS_H_

    #define PI 3.14159265358979323846264338327950

typedef struct unsigned_point {
    unsigned int x;
    unsigned int y;
} upt_t;

typedef struct int_point {
    int x;
    int y;
} ipt_t;

typedef struct long_point {
    long x;
    long y;
} lpt_t;

typedef struct vector {
    struct int_point origin;
    struct int_point direc;
    int norme;
} vec_t;

/* factorial.c */
double factorial(unsigned int x);

/* power.c */
long double power(double x, int n);

/* square_root.c */
float square_root(float x, float epsilon);
float my_sqrt(float x);

/* exponential.c */
double exponential(double x, short n_iteration);
double my_exp(double x);

/* sinus.c */
double sinus(double x, short n_iteration);
double my_sin(double x);

/* cosinus.c */
double cosinus(double x, short n_iteration);
double my_cos(double x);

/* tangent.c */
double tangent(double x, short n_iteration);
double my_tan(double x);

#endif
