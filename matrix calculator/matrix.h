#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#define max_len_string 100
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct matrix{
    double *data;
    size_t w, h;
} matrix;

matrix * matrix_alloc (size_t w, size_t h);

int matrix_realloc(matrix *m, size_t w, size_t h);

void matrix_input(matrix *m);

void matrix_output(const matrix *m);

matrix * matrix_copy (const matrix *m);

void matrix_free(matrix *m);

double * matrix_ptr (matrix *m, size_t i, size_t j);

const double * matrix_cptr (const matrix *m, size_t i, size_t j);

void matrix_set_zero (matrix *m);

void matrix_set_id (matrix *m);

matrix * matrix_alloc_zero (size_t w, size_t h);

matrix * matrix_alloc_id (size_t w, size_t h);

int matrix_assign (matrix *m1, const matrix *m2);

void matrix_dim(const matrix *m, size_t *w, size_t *h);

#endif // MATRIX_H_INCLUDED
