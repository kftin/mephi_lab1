#include <stdio.h>
#include <stdlib.h>

#include "f_lab1_manipul.h"
#include "f_lab1_in.h"

void test(){
    int mas_1[] = {1, 2, 3, 3, 4, 5, 6, 7, 8};
    int mas_2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    matrix *m1 = NULL;
    matrix *m2 = NULL;
    m2 = matrix_new();
    m1 = matrix_new();

    set_size_of(m1, sizeof(int));
    set_size_of(m2, sizeof(int));
    set_point(m1, mas_1);
    set_point(m2, mas_2);
    set_n(m1, 3);
    set_n(m2, 3);

    matrix *result = NULL;
    result = matrix_new();
    
    printf("\nfirst matrix:\n");
    output_(m1);
    printf("\nsecond matrix\n");
    output_(m2);
    printf("sum of matrix:\n");
    sum_int_matrix(m1, m2, result);//ожидаемый исход: 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 в виде матрицы 3*3
    output_(result);

    printf("\nfirst matrix:\n");
    output_(m1);
    printf("\nsecond matrix\n");
    output_(m2);
    printf("mult of matrix:\n");
    mult_int_matrix(m1, m2, result);//ожидаемый исход: 30, 24, 18, 84, 69, 54, 138, 114, 90 в виде матрицы 3*3
    output_(result);

    printf("\nfirst matrix:\n");
    output_(m1);
    mult_int_matrix_on_const(m1, 2);//ожидаемый исход: 2, 4, 6, 8, 10, 12, 14, 16, 18 в виде матрицы 3*3
    printf("\nmult matrix on const:\n");
    output_(m1);

    free(m1);
    free(m2);
    matrix_free(result);
}
