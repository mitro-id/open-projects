#include "fuctions.h"

int matrix_add (matrix *m1, const matrix *m2){
    if(m1 == NULL || m2 == NULL || (*m1).h != (*m2).h || (*m1).w != (*m2).w){
        return -1;
    }
    else{
        for(size_t i = 0; i < (*m2).h; i++){
            for(size_t j = 0; j < (*m2).w; j++){
                *matrix_ptr(m1, i, j) += *matrix_cptr(m2, i, j);
            }
        }
    }
    return 0;
}

int matrix_sub (matrix *m1, const matrix *m2){
    if(m1 == NULL || m2 == NULL || (*m1).h != (*m2).h || (*m1).w != (*m2).w){
        return -1;
    }
    else{
        for(size_t i = 0; i < (*m2).h; i++){
            for(size_t j = 0; j < (*m2).w; j++){
                *matrix_ptr(m1, i, j) -= *matrix_cptr(m2, i, j);
            }
        }
    }
    return 0;
}

void matrix_smul(matrix *m, double d){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).h; i++){
        for(size_t j = 0; j < (*m).w; j++){
            *matrix_ptr(m, i, j) *= d;
        }
    }
}

void matrix_sdiv (matrix *m, double d){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).h; i++){
        for(size_t j = 0; j < (*m).w; j++){
            *matrix_ptr(m, i, j) *= (1/d);
        }
    }
}

int matrix_add2(matrix *m, const matrix *m1, const matrix *m2){
    if(m == NULL || m1 == NULL || m2 == NULL || (*m).w != (*m2).w || (*m).h != (*m2).h || (*m).w != (*m1).w || (*m).h != (*m1).h){
        return -1;
    }
    matrix_assign(m, m1);
    matrix_add(m, m2);
    return 0;
}

int matrix_sub2(matrix *m, const matrix *m1, const matrix *m2){
    if(m == NULL || m1 == NULL || m2 == NULL || (*m).w != (*m2).w || (*m).h != (*m2).h || (*m).w != (*m1).w || (*m).h != (*m1).h){
        return -1;
    }
    matrix_assign(m, m1);
    matrix_sub(m, m2);
    return 0;
}

int matrix_smul2(matrix *m, const matrix *m1, double d){
    if(m == NULL || m1 == NULL|| matrix_assign(m, m1) == -1){
        return -1;
    }
    matrix_smul(m, d);
    return 0;
}

int matrix_sdiv2(matrix *m, const matrix *m1, double d){
    if(m == NULL || m1 == NULL|| matrix_assign(m, m1) == -1){
        return -1;
    }
    matrix_sdiv(m, d);
    return 0;
}

int matrix_mul(matrix *m1, const matrix *m2){
    if(m1 == NULL || m2 == NULL || (*m1).w != (*m2).h){
        return -1;
    }
    double sum = 0;
    matrix *m3 = matrix_alloc((*m2).w, (*m1).h);
    if(m3 == NULL){
        return -1;
    }
    for(size_t h = 0; h < (*m3).h; h++){
        for(size_t w = 0; w < (*m3).w; w++){
            for(size_t i = 0; i < (*m1).w; i++){
                sum += *matrix_ptr(m1, h, i) * *matrix_cptr(m2, i, w);
            }
            *matrix_ptr(m3, h, w) = sum;
            sum = 0.0;
        }
    }
    if(matrix_realloc(m1, (*m2).w, (*m1).h) == -1){
        matrix_free(m3);
        return -1;
    }
    matrix_assign(m1, m3);
    matrix_free(m3);
    return 0;
}

int matrix_mul2(matrix *m, const matrix *m1, const matrix *m2){
    if(m == NULL || m1 == NULL || m2 == NULL || (*m).h != (*m1).h || (*m).w != (*m2).w){
        return -1;
    }
    if(matrix_realloc(m, (*m1).w, (*m1).h) == -1){
        return -1;
    }
    matrix_assign(m, m1);
    matrix_mul(m, m2);
    return 0;
}
