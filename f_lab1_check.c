#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "f_lab1_check.h"

int check_data() {
	char *data = NULL;
	data = readline("\nmake your choice:\n");
	if (data) {
		int size = strlen(data);
		if (!size) {
			return -1;
		}
		for (int i = 0; i < size; i++) {
			if (data[i] < '0' || data[i] > '9') {
				return -1;
			}
		}
	} else {
		return -1;
	}
	int f = atoi(data);
	free(data);
	return f;
}

int check_int(char *str) {
	if (str) {
		int size = strlen(str);
		if (!size) {
			return 1;
		}
		for (int i = 0; i < size; i++) {
			if ((str[i] < '0' || str[i] > '9') && (str[i] != ' ')) {
				return 1;
			}
		}
	} else {
		return 1;
	}
	return 0;
}
