#include "path.h"

static void mx_fill(t_data *data, char **arrarr, t_int *in) {
	int **mat = data->mat;
	int k = 0;
	int i = in->size;
	int j = in->root;

	if(mx_isdigit(arrarr[j + 1][0])) {
		while(mx_strcmp(data->set[k], arrarr[j-1]) != 0)
			k++;
		if (!mat[i][k] || mat[i][k] > mx_atoi(arrarr[j+1]))
			mat[i][k] = mx_atoi(arrarr[j+1]);
	}
	else {
		while(mx_strcmp(data->set[k], arrarr[j+1]) != 0)
			k++;
		if (!mat[i][k] || mat[i][k] > mx_atoi(arrarr[j+2]))
			mat[i][k] = mx_atoi(arrarr[j+2]);
	}
}

static void mx_mat(t_data *data, char **arrarr) {
	t_int *i = malloc(sizeof(t_int));

	i->size = 0;
	while(data->set[i->size]) {
		i->root = 0;
		while(arrarr[i->root]) {
			if(mx_strcmp(data->set[i->size], arrarr[i->root]) == 0) {
				mx_fill(data, arrarr, i);
			} 	
			i->root += 1;
		}
		i->size += 1;
	}
	free(i);
	i = NULL;
}

int **mx_create_matrix(t_data *data, char ***arrarr) {
	int i = 0;
	int k = 0;

	while(data->set[i])
		i++;
	k = i;
	data->mat = malloc(sizeof(int*) * i);
	while(k >= 0) {
		data->mat[k] = malloc(sizeof(int) * i);
		k--;
	}
	mx_mat(data, *arrarr);
	return data->mat;
}
