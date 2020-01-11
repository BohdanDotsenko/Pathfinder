#ifndef PATH_H
#define PATH_H

#include "libmx.h"

typedef struct s_data {
	int size;
	char **set;
    int **mat;
    char **buf;
    char *res;
}       t_data;

typedef struct s_int {
	int size;
	int root;
}		t_int;

// void mx_count_set(char **arr, char *nIslands, int *count);
void mx_join(char **res, char *s2);
void mx_delMat(int ***matrix, char **set);
void mx_check_empty_line(char **lines, char *file);
void mx_errors(int argc, char *file, char **argv);
void mx_parse(char *fd, t_data *data);
void mx_create_arrarr(char **lines, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *nIslands);
void mx_print_mat(int **mat, char **set);
void mx_algo(int **matrix, char **set);
void mx_arr(char **lines, char ***arr);
int **mx_create_matrix(t_data *data, char ***arrarr);

#endif
