#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED
#include "fuctions.h"

int matrix_T(matrix *m);

void matrix_rear_col(matrix *m, size_t column1, size_t column2);

void matrix_rear_str(matrix *m, size_t string1, size_t string2);

void matrix_mul_str(matrix *m, size_t string, double value);

void matrix_div_str(matrix *m, size_t string, double value);

void matrix_add_str(matrix *m, size_t string, size_t string2_add, double value);

double matrix_norm_1(const matrix *m);



#endif // OPERATIONS_H_INCLUDED
