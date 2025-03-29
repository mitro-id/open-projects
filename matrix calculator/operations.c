#include "operations.h"

int matrix_T(matrix *m){
    if(m == NULL){
        return -1;
    }
    matrix *m1 = matrix_copy(m);
    if(m1 == NULL || matrix_realloc(m, (*m).h, (*m).w) == -1){
        return -1;
    }
    for(size_t i = 0; i < (*m).h; i++){
        for(size_t j = 0; j < (*m).w; j++){
            *matrix_ptr(m, i, j) = *matrix_ptr(m1, j, i);
        }
    }
    matrix_free(m1);
    return 0;
}

void matrix_rear_str(matrix *m, size_t string1, size_t string2){
    if(m == NULL){
        return;
    }
    double d1;
    for(size_t i = 0; i < (*m).w; i++){
        d1 = *matrix_ptr(m, string1, i);
        *matrix_ptr(m, string1, i) = *matrix_ptr(m, string2, i);
        *matrix_ptr(m, string2, i) = d1;
    }
}

void matrix_rear_col(matrix *m, size_t column1, size_t column2){
    if(m == NULL){
        return;
    }
    double d1;
    for(size_t i = 0; i < (*m).h; i++){
        d1 = *matrix_ptr(m, i, column1);
        *matrix_ptr(m, i, column1) = *matrix_ptr(m, i, column2);
        *matrix_ptr(m, i, column2) = d1;
    }
}

void matrix_mul_str(matrix *m, size_t string, double value){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).w; i++){
        *matrix_ptr(m, string, i) *= value;
    }
}

void matrix_div_str(matrix *m, size_t string, double value){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).w; i++){
        *matrix_ptr(m, string, i) *= (1 / value);
    }
}

void matrix_add_str(matrix *m, size_t string, size_t string_add, double value){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).w; i++){
        *matrix_ptr(m, string, i) += *matrix_ptr(m, string_add, i) * value;
    }
}

double matrix_norm_1(const matrix *m){
    if(m == NULL){
        return 0;
    }
    double sum, sum1 = 0;
    for(size_t i = 0; i < (*m).h; i++){
        sum = 0;
        for(size_t j = 0; j < (*m).w; j++){
            sum += fabs(*matrix_cptr(m, i, j));
        }
        sum1 = sum1 < sum ? sum : sum1;
    }
    return sum1;
}
