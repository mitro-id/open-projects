#include "problems.h"

matrix *matrix_exp(matrix *m, double eps){
    if(m == NULL){
        return NULL;
    }
    size_t w, h;
    matrix_dim(m, &w, &h);
    matrix *m1 = matrix_alloc_zero(w, h);
    matrix *m2 = matrix_alloc_id(w, h);
    if(m1 == NULL || m2 == NULL){
        return NULL;
    }
    double count = 1;
    while(matrix_norm_1(m2) >= eps){
        matrix_add(m1, m2);
        matrix_mul(m2, m);
        matrix_sdiv(m2, count);
        count += 1;
    }
    matrix_free(m2);
    return m1;
}

matrix *matrix_gauss(matrix *A, matrix *B){
    matrix *a = matrix_copy(A);
    matrix *b = matrix_copy(B);
    if(a == NULL || b == NULL || A == NULL || B == NULL){
        return NULL;
    }
    size_t w, h;
    matrix_dim(a, &w, &h);
    double mx, value;
    size_t mx_i;
    for(size_t i = 0; i < h; i++){
        mx = 0;
        mx_i = w + 1;
        for(size_t j = i; j < h; j++){
            if(fabs(*matrix_ptr(a, j, i)) > mx){
                mx = *matrix_ptr(a, j, i);
                mx_i = j;
            }
        }
        if (mx_i == w + 1){
            return NULL;
        }
        matrix_rear_str(a, mx_i, i);
        matrix_rear_str(b, mx_i, i);
        for(size_t j = 0; j < h; j++){
            if(j != i){
                value = *matrix_ptr(a, j, i) / *matrix_ptr(a, i, i);
                matrix_add_str(a, j, i, -value);
                matrix_add_str(b, j, i, -value);
            }
        }
        matrix_div_str(b, i, *matrix_ptr(a, i, i));
        matrix_div_str(a, i, *matrix_ptr(a, i, i));
    }
    matrix_free(a);
    return b;
}
