#include "path.h"

static int find_path(t_data *data, t_var var, int *d, int **way) {
    for (int i = 0; i < data->size; i++) {
        if (data->mat[var.mi][i] > 0) {
            var.temp = var.min + data->mat[i][var.mi];
            if (var.temp <= d[i]) {
                for (int e = 0; way[e][0] != -1; e++) {
                    for (int r = 0; way[e][r] != -1; r++) {
                        if (way[e][r + 1] == - 1 && way[e][r] == var.mi) {
                            for (int m = 0; m < data->size + 2; m++)
                                way[var.count + 1][m] = way[e][m];
                                way[var.count + 1][r + 1] = i;
                                var.count++;
                                break;
                        }
                    }
                }
            d[i] = var.temp;
            }
        }
    }
    return var.count;
}

t_var variables() {
    t_var var;

    var.count = 0;
    var.temp = 0;
    var.mi = 999999999;
    var.min = 1000000000;
    return var;
}

static void minminindex(t_data *data, int *d, int *v) {
    for (int k = 0; k < data->size; k++){
        d[k] = 1000000000;
        v[k] = 1;
    }
}

void mx_deyxtra(t_data *data, int **way, int begin, int *d) {
    int v[data->size];
    t_var var = variables();
    way[0][0] = begin;

    minminindex(data, d, v);
    d[begin] = 0;
    for (int k = 0; k < data->size; k++) {
        var.min = 1000000000;
        var.mi = 1000000000;
        for (int i = 0; i < data->size; i++) {
            if (v[i] == 1 && d[i] <= var.min) {
                var.min = d[i];
                var.mi = i;
            }
        }
        if (var.mi != 1000000000) {
            var.count = find_path(data, var, d, way);
            v[var.mi] = 0;
        }
    }
}
