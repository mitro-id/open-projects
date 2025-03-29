#include "fuctions.h"
#include "matrix.h"
#include "operations.h"
#include "problems.h"
#include <sys/stat.h>

int main()
{
    printf("Welcome to matrix calculator\nSelect an action:\n1) Calculate the exponent of a matrix\n2) Calculate the roots of a system of linear equations\n");
    int w, n;
    matrix *m1, *m2, *m3;
    char *buffer = malloc(max_len_string);
    do{
        fgets(buffer, max_len_string, stdin);
        n = atoi(buffer);
        if(n != 1 && n != 2){
            printf("Try again\n");
        }
    }while(n != 1 && n != 2);
    system("cls");
    if(n == 1){
        printf("Enter dim matrix(w)\n");
        fgets(buffer, max_len_string, stdin);
        w = atoi(buffer);
        m1 = matrix_alloc((size_t)w, (size_t)w);
        printf("Enter matrix elements\n");
        matrix_input(m1);
        m2 = matrix_exp(m1, 0.000001);
        system("cls");
        printf("Matrix\n");
        matrix_output(m2);
    }
    else{
        printf("Enter dim matrix(w)\n");
        fgets(buffer, max_len_string, stdin);
        w = atoi(buffer);
        m1 = matrix_alloc((size_t)w, (size_t)w);
        printf("Enter matrix elements\n");
        matrix_input(m1);
        printf("Enter free members\n");
        m2 = matrix_alloc(1, (size_t)w);
        matrix_input(m2);
        system("cls");
        m3 = matrix_gauss(m1, m2);
        if(m3 == NULL){
            printf("No rots or error\n");
        }
        else{
            printf("Matrix\n");
            matrix_output(m3);
            printf("\n||A*x - b||\n");
            matrix_mul(m1, m3);
            matrix_sub(m1, m2);
            printf("%lf\n", matrix_norm_1(m1));
            matrix_free(m3);
        }
    }
    matrix_free(m1);
    matrix_free(m2);
    free(buffer);
    printf("End of work\n");
    return 0;
}
