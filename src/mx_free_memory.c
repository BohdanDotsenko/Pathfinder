#include "path.h"

void mx_free_memory(t_data *data, int *temp, int **way) {
    int i = 0;

    free(temp);
    temp = NULL;
    for (i = 0; i < data->size *data->size; i++) {
        free(way[i]);
        way[i] = NULL;
    }
    free(way);
    way = NULL;
    for (i = 0; i < data->size; i++) {
        free(data->mat[i]);
        data->mat[i] = NULL;
    }
    free(data->mat);
    for (i = 0; i < data->size; i++) {
        free(data->set[i]);
        data->set[i] = NULL;
    }
}
