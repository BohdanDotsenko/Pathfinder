#include "path.h"

void mx_parse(char *fd, t_data *data) {
	char **arrarr = NULL;
	char **lines = mx_strsplit(fd, '\n');
	data->size = mx_atoi(lines[0]);
	
	
	mx_arr(lines, &arrarr);
	mx_create_set(&(data->set), &arrarr, lines[0]);
	//data->mat = mx_create_matrix(data, &arrarr);
	// printf("%d", data->mat[0][0]);
	mx_del_strarr(&lines);
	mx_del_strarr(&arrarr);
}
