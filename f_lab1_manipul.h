#ifndef F_LAB1_MANIPUL
#define F_LAB1_MANIPUL

struct matrix_;

typedef struct matrix_ matrix;

matrix *matrix_new();
void matrix_free(matrix *m);

struct int_complex {
	int a;
	int b;
} typedef int_complex;
int_complex *int_complex_new();

int set_point(matrix *m, void *point);
int set_size_of(matrix *m, int size);
int set_n(matrix *m, int n);

void *get_point(matrix *m);
int get_size_of(matrix *m);
int get_n(matrix *m);

void *manipul(matrix *m1, matrix *m2, matrix *result);

void mult_int_matrix_on_const(matrix *m, int cnst);
void mult_complex_matrix_on_const(matrix *m, int cnst);

void sum_int_matrix(matrix *m1, matrix *m2, matrix *result);
void sum_complex_matrix(matrix *m1, matrix *m2, matrix *result);

void mult_int_matrix(matrix *m1, matrix *m2, matrix *result);
void mult_complex_matrix(matrix *m1, matrix *m2, matrix *result);

#endif
