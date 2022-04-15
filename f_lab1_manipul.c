#include <stdio.h>
#include <stdlib.h>

#include "f_lab1_manipul.h"
#include "f_lab1_check.h"
#include "f_lab1_in.h"

struct matrix_ {
	void *point;
	int size_of;
	int n;
};

int_complex *int_complex_new() {
	int_complex *new = NULL;
	new = calloc(1, sizeof(int_complex));
	return new;
}

matrix *matrix_new() {
	matrix *new = NULL;
	new = calloc(1, sizeof(matrix));
	return new;
}

void matrix_free(matrix *m) {
	free(get_point(m));
	free(m);
}

int set_point(matrix *m, void *point) {
	if (point) {
		m->point = point;
		return 0;
	} else {
		return 1;
	}
}

int set_size_of(matrix *m, int size) {
	if (size) {
		m->size_of = size;
		return 0;
	} else {
		return 1;
	}
}

int set_n(matrix *m, int N) {
	if (N) {
		m->n =  N;
		return 0;
	} else {
		return 1;
	}
}

void *get_point(matrix *m) {
	return m->point;
}

int get_size_of(matrix *m) {
	return m->size_of;
}

int get_n(matrix *m) {
	return m->n;
}

void mult_int_matrix_on_const(matrix *m, int cnst) {
	int *mas = (int *)(get_point(m));
	int n = get_n(m);
	for (int i = 0; i < n * n; i++) {
		mas[i] = mas[i] * cnst;
	}
}

void mult_complex_matrix_on_const(matrix *m, int cnst) {
	int_complex *mas = (int_complex *)(get_point(m));
	int n = get_n(m);
	for (int i = 0; i < n * n; i++) {
		mas[i].a = mas[i].a * cnst;
		mas[i].b = mas[i].b * cnst;
	}
}

void mult_int_matrix(matrix *m1, matrix *m2, matrix *result) {
	int *mas = NULL;
	int *mas_1 = (int *)get_point(m1);
	int *mas_2 = (int *)get_point(m2);
	if (get_n(m1) != get_n(m2)) {
		printf("different size, impossible\n");
        return;
	}
	if (get_point(result)) {
	    free(get_point(result));
	}
	mas = calloc(get_n(m1) * get_n(m1), sizeof(int));
    int n = get_n(m1);
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mas[i * n + j] += mas_1[i * n + k] * mas_2[k * n + j];
            }
        }
    } 
	set_point(result, (void *)mas);
	set_n(result, get_n(m1));
	set_size_of(result, sizeof(int));
}

void mult_complex_matrix(matrix *m1, matrix *m2, matrix *result) {
	int_complex *mas = NULL;
	int_complex *mas_1 = (int_complex *)get_point(m1);
	int_complex *mas_2 = (int_complex *)get_point(m2);
	if (get_n(m1) != get_n(m2)) {
		printf("different size, impossible\n");
        return;
	}
	if (get_point(result)) {
	    free(get_point(result));
	}
	mas = calloc(get_n(m1) * get_n(m1), sizeof(int_complex));
    int n = get_n(m1);
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mas[i * n + j].a += mas_1[i * n + k].a * mas_2[k * n + j].a - mas_1[i * n + k].b * mas_2[k * n + j].b;
                mas[i * n + j].b += mas_1[i * n + k].a * mas_2[k * n + j].b + mas_1[i * n + k].b * mas_2[k * n + j].a;
            }
        }
    }
	set_point(result, (void *)mas);
	set_n(result, get_n(m1));
	set_size_of(result, sizeof(int_complex));
}


void sum_int_matrix(matrix *m1, matrix *m2, matrix *result) {
	int *mas = NULL;
	int *mas_1 = (int *)get_point(m1);
	int *mas_2 = (int *)get_point(m2);
	if (get_n(m1) != get_n(m2)) {
		printf("different size, impossible\n");
	} else {
		if (get_point(result)) {
			free(get_point(result));
		}
		mas = calloc(get_n(m1) * get_n(m1), sizeof(int));
		for (int i = 0; i < get_n(m1) * get_n(m1); i++) {
			mas[i] = mas_1[i] + mas_2[i];
		}
		set_point(result, (void *)mas);
		set_n(result, get_n(m1));
		set_size_of(result, sizeof(int));
	}
}

void sum_complex_matrix(matrix *m1, matrix *m2, matrix *result) {
	int_complex *mas = NULL;
	int_complex *mas_1 = (int_complex *)get_point(m1);
	int_complex *mas_2 = (int_complex *)get_point(m2);
	if (get_n(m1) != get_n(m2)) {
		printf("different size, impossible\n");
	} else {
		if (get_point(result)) {
			free(get_point(result));
		}
		mas = calloc(get_n(m1) * get_n(m1), sizeof(int_complex));
		for (int i = 0; i < get_n(m1) * get_n(m1); i++) {
			mas[i].a = mas_1[i].a + mas_2[i].a;
			mas[i].b = mas_1[i].b + mas_2[i].b;
		}
		set_point(result, (void *)mas);
		set_n(result, get_n(m1));
		set_size_of(result, sizeof(int_complex));
	}
}

/*void mult_int_matrix_on_matrix(matrix *m1, matrix *m2, matrix *result) {
	int *mas = NULL;
	int *mas_1 = (int *)get_point(m1);
	int *mas_2 = (int *)get_point(m2);
	if (get_n(m1) != get_n(m2)) {
		printf("different size, impossible\n");
	} else {
		if (get_point(result)) {
			free(get_point(result));
		}
		mas = calloc(get_n(m1) * get_n(m1), sizeof(int));

	}
}*/

void *manipul(matrix *m1, matrix *m2, matrix *result) {
	int f = -1;
	printf("0)multiply on const m1\n1)multiply on const m2\n2)multiply\n3)sum\n");
	f = check_data();
	switch (f) {
		case 0:
			if (get_point(m1)) {
				int cnst_1 = 0;
				printf("Enter your const\n");
				scanf("%d", &cnst_1);
				if (get_size_of(m1) == sizeof(int)) {
					mult_int_matrix_on_const(m1, cnst_1);
				} else {
					mult_complex_matrix_on_const(m1, cnst_1);
				}
			} else {
				printf("there is no matrix\n\n");
			}
			break;
		case 1:
			if (get_point(m2)) {
				int cnst_2 = 0;
				printf("Enter your const\n");
				scanf("%d", &cnst_2);
				if (get_size_of(m2) == sizeof(int)) {
					mult_int_matrix_on_const(m2, cnst_2);
				} else {
					mult_complex_matrix_on_const(m2, cnst_2);	
				}
			} else {
				printf("there is no matrix\n\n");
			}
			break;
		case 2:
			
			if (get_size_of(m1) == sizeof(int) && get_size_of(m2) == sizeof(int)) {
				mult_int_matrix(m1, m2, result);
			} else if (get_size_of(m1) == sizeof(int_complex) && get_size_of(m2) == sizeof(int_complex)) {
				mult_complex_matrix(m1, m2, result);
			} else {
				printf("different types\n");
			}
			break;
		case 3:
			if (get_size_of(m1) == sizeof(int) && get_size_of(m2) == sizeof(int)) {
				sum_int_matrix(m1, m2, result);
			} else if (get_size_of(m1) == sizeof(int_complex) && get_size_of(m2) == sizeof(int_complex)) {
				sum_complex_matrix(m1, m2, result);
			} else {
				printf("different types\n");
 			}
			break;
		default:
			printf("You make a mistake, try again\n");
			break;
	}
}
