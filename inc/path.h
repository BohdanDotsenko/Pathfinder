#ifndef PATH_H
#define PATH_H

#include "libmx.h"

typedef struct s_data {
	int size;
	char **set;
    int **mat;
}       t_data;

typedef struct s_int {
	int size;
	int root;
}		t_int;


typedef struct s_var {
	int count;
	int temp;
	int mi;
	int min;
}		t_var;

void mx_deyxtra(t_data *data, int **way, int begin, int *d);
void mx_check_empty_line(char **lines, char *file);
void mx_errors(int argc, char *file, char **argv);
void mx_parse(char *fd, t_data *data);
void mx_create_arrarr(char **lines, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *nIslands);
void mx_print_mat(int **mat, char **set);
void mx_algo(t_data *data);
void mx_arr(char **lines, char ***arr);
int **mx_create_matrix(t_data *data, char **lines);
void mx_printway(t_data *data, int *way);
void mx_printerr_exit(const char *s);
void mx_check_spaces(char **lines, char *file);
void mx_free_memory(t_data *data, int *temp, int **way);

#endif
