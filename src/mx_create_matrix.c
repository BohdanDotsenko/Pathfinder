#include "path.h"

static void create_mem_mat(t_data *data, char ***lines) {
	data->mat = (int **)malloc(sizeof(int *) * data->size);

	for (int i = 0; i < mx_atoi(*lines[0]); i++) {
		data->mat[i] = (int *)malloc(sizeof(int) * data->size);
		for (int j = 0; j < mx_atoi(*lines[0]); j++) {
			data->mat[i][j] = 1000000000;
			//2147483647
		}
	}
}

static void mx_value(t_data *data, char *str, int i1, int i2) {
	for (int i = 0; str[i]; i++) {
		if(str[i] == ',') {
			data->mat[i1][i2] = mx_atoi(&str[i + 1]);
			data->mat[i2][i1] = mx_atoi(&str[i + 1]);
		}
	}
}

int **mx_create_matrix(t_data *data, char **lines){
	int index1;
	int index2;
	int flag;

	create_mem_mat(data, &lines);
	for (int i = 1; lines[i]; i++) {
		flag = 1;
		for (int j = 0; j < mx_atoi(lines[0]); j++) {
			if (mx_get_substr_index(lines[i], 
			data->set[j]) >= 0  && flag == 1) {
				index1 = j;
				flag = -1;
			}
			if (mx_get_substr_index(lines[i], data->set[j]) >= 0)
				index2 = j;
		}
		mx_value(data, lines[i], index1, index2);
	}
	return data->mat;
}
