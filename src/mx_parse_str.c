#include "pathfinder.h"

static void check_points_count(int j, t_data **pf) {
    if (j > (*pf)->cityes)
        mx_print_error(ERROR_LOGIC, NULL, NULL);
}

static void count_plus(int *count, int *j) {
    (*count) += 1;
    (*j) += 1;
}

static void del_buf(char ***ar1, char ***ar2) {
    mx_del_strarr(ar1);
    mx_del_strarr(ar2);
}

int mx_parse_str(t_data **data, char **file) {
    int j = 0;
    int count = 0;

    for (int i = 1; i < (*data)->size_arr; i++) {
        char **ar1 = mx_strsplit(file[i], '-');
        char **ar2 = mx_strsplit(ar1[1], ',');

        check_points_count(j, pf);
        if (mx_get_arrstr_index((const char **)((*data)->pA), ar1[0]) == -1) {
            ((*data)->pA)[j] = mx_strndup(ar1[0], mx_strlen(ar1[0]));
            count_plus(&count, &j);
        }
        if (mx_get_arrstr_index((const char **)((*data)->pA), ar2[0]) == -1) {
            ((*data)->pA)[j] = mx_strndup(ar2[0], mx_strlen(ar2[0]));
            count_plus(&count, &j);
        }
        del_buf(&ar1, &ar2);
    }
    return count;
}
