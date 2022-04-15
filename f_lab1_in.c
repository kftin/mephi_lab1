#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#include "f_lab1_manipul.h"
#include "f_lab1_check.h"
#include "f_lab1_in.h"

void input(matrix *m1, matrix *m2) {
	int f = -1, flag = 0;
	printf("0)integer_matrix1\n1)complex_matrix1\n2)integer_matrix2\n3)complex_matrix2");
	f = check_data();
	switch (f) {
		case 0:
			flag = set_size_of(m1, sizeof(int));
			input_(m1);
			break;
		case 1:
			flag = set_size_of(m1, sizeof(int_complex));
			input_(m1);
			break;
		case 2:
			flag = set_size_of(m2, sizeof(int));
			input_(m2);
			break;
		case 3:
			flag = set_size_of(m2, sizeof(int_complex));
			input_(m2);
			break;
		default:
			printf("You make a mistake, try again\n");
			break;
	}
}


void output(matrix *m1, matrix *m2, matrix *result) {
	int f = -1, flag = 0;
	printf("0)m1\n1)m2\n2)result\n");
	f = check_data();
	switch (f) {
		case 0:
			output_(m1);
			break;
		case 1:
			output_(m2);
			break;
		case 2:
			output_(result);
			break;
		default:
			printf("You make a miistake, try again\n");
	}
}

void output_(matrix *m) {
	int *mas1 = NULL;
	int_complex *mas2 = NULL;
	if (get_size_of(m) == sizeof(int)) {
		mas1 = (int *)get_point(m);
		if (!mas1) {
			printf("\nthere is no matrix\n");
		} else {
			for (int i = 0; i < get_n(m) * get_n(m); i++) {
				if (i % get_n(m) == 0) {
					printf("\n");
				}
				printf("%d ", mas1[i]);
			}
		}
	} else {
		mas2 = (int_complex *)get_point(m);
		if (!mas2) {
			printf("\nthere is no matrix\n");
		} else {
			for (int i = 0; i < get_n(m) * get_n(m); i++) {
				if (i % get_n(m) == 0) {
					printf("\n");
				}
				if (mas2[i].b < 0) {
					printf("%d-%di ", mas2[i].a, mas2[i].b * (-1));
				} else {
					printf("%d+%di ", mas2[i].a, mas2[i].b);
				}
			}
		}
	}
	printf("\n\n");
}

void input_(matrix *m) {
	if (get_point(m)) {
		free(get_point(m));	
	}
	int *mas_1 = NULL;
	int_complex *mas_2 = NULL;
	int size_array = 0;
	char *str = NULL;
	str = readline("Enter your row\n");
	char *matrix_element = strtok(str, " \t");
	while (matrix_element) {
		if (get_size_of(m) == sizeof(int)){
			mas_1 = realloc(mas_1, (size_array + 1) * sizeof(int));
			mas_1[size_array] = atoi(matrix_element);
		} else {
			mas_2 = realloc(mas_2, (size_array + 1) * sizeof(int_complex));
			//printf("\"%s\"\n", matrix_element);
			int_complex *t = collect_number(matrix_element);
			mas_2[size_array] = *t;
			free(t);
		}
		size_array++;
		matrix_element = strtok(NULL, " \t");
	}
	free(str);
	int i = 1;
	while (i < size_array) {
		char *str = NULL;
		str = readline("Enter your row\n");
		int tmp = size_array * i;
		char *matrix_element = strtok(str, " \t");
		while (matrix_element) {
			if (get_size_of(m) == sizeof(int)) {
				mas_1 = realloc(mas_1, (tmp + 1) * sizeof(int));
				mas_1[tmp] = atoi(matrix_element);
			} else {
				mas_2 = realloc(mas_2, (tmp + 1) * sizeof(int_complex));
				//printf("%s\n", matrix_element);
				int_complex *t = collect_number(matrix_element);
				mas_2[tmp] = *t;
				free(t);
			}
			tmp++;
			matrix_element = strtok(NULL, " \t");
		}
		free(str);
		i++;
	}
	set_n(m, size_array);
	if (get_size_of(m) == sizeof(int)) {
		set_point(m, (void *)mas_1);
	} else {
		set_point(m, (void *)mas_2);
	}
}

int_complex *collect_number(char *number) {
	int i = 0;
	if (number[0] == '-') {
		i++;
	}
	while (number[i] != '+' && number[i] != '-') {
		i++;
	}
	printf("%c\n", number[i]);
	char *a1 = NULL;
	a1 = calloc(i + 1, 1);
	memcpy(a1, number, i);
	a1[i] = '\0';
	int a = atoi(a1);
	free(a1);
	char *b1 = NULL;
	int k = i + 1;
	while (number[k] != 'i') {
		k++;
	}
	b1 = calloc(1, k - i + 1);
	memcpy(b1, number + i, k - i);
	b1[k - i] = '\0';
	int b  = atoi(b1);
	free(b1);
	int_complex *z = int_complex_new();
	z->a = a;
	z->b = b;
	return z;
}
