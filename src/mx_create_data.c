#include"pathfinder.h"

t_data *mx_create_pf_variables(char **file) {
    t_data *pf = (t_data *)malloc(sizeof(t_data));
    long pc = mx_atoi(file[0]);

    if (pc > 2147483647 || pc <= 0)
        mx_print_error(ERROR_LINE, "1", ERROR_INVALID);
    pf->cityes = pc;
    pf->size_arr = mx_arr_size((const char **)file);
    pf->size_arr -= mx_check_fts_bug(file[pf->size_arr- 1]);
    pf->matrix = mx_create_mat(pf->cityes);
    pf->pA = mx_create_points(pf->cityes);
    pf->dey = mx_create_dey(pf->cityes);
    return pf;
}

static bool is_symbol(char c) {
    if (c >= 32 && c <= 126) {
        return true;
    }
    return false;
}

static int mx_check_fts_bug(char *str) {
    if (!is_symbol(str[0]))
        return 1;
    return 0;
}

int **mx_create_mat(int pC) {
    int **mat = (int **)malloc(sizeof(int *) * pC);

    for (int x = 0; x < pC; x++) {
        mat[x] = (int *)malloc(sizeof(int) * pC);
        for (int y = 0; y < pC; y++) {
            mat[x][y] = 2147483647;
        }
    }
    return mat;
}

char **mx_create_points(int pC) {
    char **pA = (char **)malloc(sizeof(char *) * pC + 1);
    for (int i = 0; i <= pC; i++)
        pA[i] = NULL;
    return pA;
}

t_dey *mx_create_dey(int cityes) {
    t_dey *dey = (t_dey *)malloc(sizeof(t_dey));
    dey->l = (int *)malloc(sizeof(int) * cityes);
    dey->t = (int *)malloc(sizeof(int) * cityes);
    dey->f = (int **)malloc(sizeof(int *) * cityes);

    for (int y = 0; y < cityes; y++) {
        dey->l[y] = 0;
        dey->t[y] = 0;
        dey->f[y] = (int *)malloc(sizeof(int) * cityes);
        for (int x = 0; x < cityes; x++) {
            dey->f[y][x] = 0;
        }
    }
    return dey;
}
