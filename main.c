#include <stdio.h>
#include <stdlib.h>

#include "f_lab1_manipul.h"
#include "f_lab1_check.h"
#include "f_lab1_in.h"
#include "test.h"

int main() {
	matrix *m1 = NULL, *m2 = NULL, *result = NULL;
	result = matrix_new();
	m1 = matrix_new();
	m2 = matrix_new();
	int flag = -1;
	while (flag != -2) {
		printf("0) input\n1) output\n2) matrix operations\n3) finish\n4) tests\n");
		flag = check_data();
		switch (flag) {
			case 0:
				input(m1, m2);
				break;
			case 1:
				output(m1, m2, result);
				break;
			case 2:
				manipul(m1, m2, result);
				break;
			case 3:
				flag = -2;
				break;
            case 4:
                test();
			default:
				printf("You make a mistake, try again\n");
				break;
		}
	}
	matrix_free(result);
	matrix_free(m1);
	matrix_free(m2);	
}
