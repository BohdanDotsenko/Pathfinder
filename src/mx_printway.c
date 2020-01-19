#include "path.h"

static int count(int *way) {
    int count = 0;
    for (int i = 0; way[i] != -1; i++)
        count++;
    return count;
}

static void last(int size, int res) {
    if (size > 2) {
        mx_printstr(" = ");
        mx_printint(res);
    }
    mx_printstr("\n========================================\n");
}

static void second(t_data *data, int *way, int size) {
    mx_printstr("========================================\nPath: ");
    mx_printstr(data->set[way[0]]);
    mx_printstr(" -> ");
    mx_printstr(data->set[way[size - 1]]);
    mx_printstr("\nRoute: ");
}

void mx_printway(t_data *data, int *way) {
    int res = 0;
    int size = count(way);

    if (size < 2)
        return;
    second(data, way, size);
    for (int i = 0; i < size - 1; i++) {
        mx_printstr(data->set[way[i]]);
        mx_printstr(" -> ");
    }
    mx_printstr(data->set[way[size - 1]]);
    mx_printstr("\nDistance: ");
    for (int i = 0; i < size - 1; i++) {
        mx_printint(data->mat[way[i]][way[i + 1]]);
        if (i != size - 2)
            mx_printstr(" + ");
        res = res + data->mat[way[i]][way[i + 1]];
    }
    last(size, res);
}
