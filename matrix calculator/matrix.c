#include "matrix.h"

matrix *matrix_alloc(size_t w, size_t h){
    matrix *mat = malloc(sizeof(matrix));
    if(mat == NULL){
        return NULL;
    }
    (*mat).w = w;
    (*mat).h = h;
    (*mat).data = malloc(sizeof(double) * w * h);
    if((*mat).data == NULL){
        return NULL;
    }
    return mat;
}

int matrix_realloc(matrix *m, size_t w, size_t h){
    if(m == NULL){
        return -1;
    }
    free((*m).data);
    (*m).data = malloc(sizeof(double) * w * h);
    if((*m).data == NULL){
        return -1;
    }
    (*m).w = w;
    (*m).h = h;
    return 0;
}

void matrix_free(matrix *m){
    if(m == NULL){
        return;
    }
    free((*m).data);
    free(m);
}

double *matrix_ptr(matrix *m, size_t i, size_t j){
    if(m == NULL){
        return NULL;
    }
    return (*m).data + i * (*m).w + j;
}

const double *matrix_cptr(const matrix *m, size_t i, size_t j){
    if(m == NULL){
        return NULL;
    }
    return (*m).data + i * (*m).w + j;
}

void matrix_set_zero(matrix *m){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).h; i++){
        for(size_t j = 0; j < (*m).w; j++){
            *matrix_ptr(m, i, j) = 0;
        }
    }
}

void matrix_set_id(matrix *m){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).h; i++){
        for(size_t j = 0; j < (*m).w; j++){
            if(i == j){
                *matrix_ptr(m, i, j) = 1;
            }
            else{
                *matrix_ptr(m, i, j) = 0;
            }
        }
    }
}

matrix *matrix_alloc_zero (size_t w, size_t h){
    matrix *m = matrix_alloc(w, h);
    if(m == NULL){
        return NULL;
    }
    matrix_set_zero(m);
    return m;
}

matrix *matrix_alloc_id (size_t w, size_t h){
    matrix *m = matrix_alloc(w, h);
    if(m == NULL){
        return NULL;
    }
    matrix_set_id(m);
    return m;
}

int matrix_assign(matrix *m1, const matrix *m2){
    if(m1 == NULL || m2 == NULL || sizeof((*m2).data) != sizeof((*m1).data) || (*m2).w != (*m1).w || (*m2).h != (*m1).h){
        return -1;
    }
    else{
        for(size_t i = 0; i < (*m2).h; i++){
            for(size_t j = 0; j < (*m2).w; j++){
                *matrix_ptr(m1, i, j) = *matrix_cptr(m2, i, j);
            }
        }
    }
    return 0;
}

matrix *matrix_copy (const matrix *m){
    if(m == NULL){
        return NULL;
    }
    matrix *m1 = matrix_alloc((*m).w, (*m).h);
    int p = matrix_assign(m1, m);
    if(p == -1){
        return NULL;
    }
    return m1;
}

void matrix_input(matrix *m){
    if(m == NULL){
        return;
    }
    char *buffer = malloc(max_len_string);
    if(buffer == NULL){
        return;
    }
    char *end;
    for(size_t i = 0; i < (*m).h; i++){
        for(size_t j = 0; j < (*m).w; j++){
            printf("Element i = %d, j = %d: ", (int)i, (int)j);
            fgets(buffer, max_len_string, stdin);
            *matrix_ptr(m, i, j) = strtod(buffer, &end);
        }
    }
    free(buffer);
}

void matrix_output(const matrix *m){
    if(m == NULL){
        return;
    }
    for(size_t i = 0; i < (*m).h; i++){
        for(size_t j = 0; j < (*m).w; j++){
            printf("%-10.2lf ", *matrix_cptr(m, i, j));
        }
        printf("\n");
    }
}

void matrix_dim(const matrix *m, size_t *w, size_t *h){
    if(m == NULL || w == NULL || h == NULL){
        return;
    }
    *w = (*m).w;
    *h = (*m).h;
}
