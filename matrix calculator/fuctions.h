#ifndef FUCTIONS_H_INCLUDED
#define FUCTIONS_H_INCLUDED
#include "matrix.h"

int matrix_add (matrix *m1, const matrix *m2);

int matrix_sub (matrix *m1, const matrix *m2);

void matrix_smul (matrix *m, double d);

void matrix_sdiv (matrix *m, double d);

int matrix_add2 (matrix *m, const matrix *m1, const matrix *m2);

int matrix_sub2 (matrix *m, const matrix *m1, const matrix *m2);

int matrix_smul2 (matrix *m, const matrix *m1, double d);

int matrix_sdiv2 (matrix *m, const matrix *m1, double d);

int matrix_mul(matrix *m1, const matrix *m2);

int matrix_mul2(matrix *m, const matrix *m1, const matrix *m2);

#endif // FUCTIONS_H_INCLUDED
