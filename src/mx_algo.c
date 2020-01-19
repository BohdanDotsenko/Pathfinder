#include "path.h"

static void remass(t_data *data, int **way){
    for (int i = 0; i < data->size * data->size; i ++) {
        for (int j = 0; j < data->size + 2; j ++)  
            way[i][j] = -1;
    }
}

static bool bool_way(t_data *data, int *way, int *temp, int begin) {
    int result = 0;
    int i = 0;
    
    for (i = 0; way[i + 1] != -1; i++) {
        result = result + data->mat[way[i]][way[i + 1]];
    }
    if (temp[way[i]] == result && way[i] > begin)
        return true;
    return false;
}

static void sort_2(t_data *data, int **way) {
    int buf[data->size + 2];
    int maxi;
    int maxj;
    int m;

    for ( int i = 0; i < data->size * data->size; i ++) {
        for (int j = i + 1; j < data->size * data->size; j ++) {
            for(m = 0; way[i][m] != -1; m++)
                maxi = way[i][m];
            for(m = 0; way[j][m] != -1; m++)
                maxj = way[j][m];
            for (int k = 0; way[j][k] != -1; k++) {
                if (way[i][k] > way[j][k] && maxi == maxj)
                    for (m = 0; m < data->size + 2; m++) {
                        buf[m] = way[i][m];
                        way[i][m] = way[j][m];
                        way[j][m] = buf[m];
                    }
            } 
        }
    }
}

static void sort_mass(t_data *data, int **way) {
    int m = 0;
    int buf[data->size + 2];
    int maxi;
    int maxj;

    for ( int i = 0; way[i][0] != -1; i ++) {
        for (int j = i + 1; way[j][0] != -1; j ++) {
            for(m = 0; way[i][m] != -1; m++)
                maxi = way[i][m];
            for(m = 0; way[j][m] != -1; m++)
                maxj = way[j][m];
            if (maxi > maxj) {
                for (m = 0; m < data->size + 2; m++) {
                    buf[m] = way[i][m];
                    way[i][m] = way[j][m];
                    way[j][m] = buf[m];
                }
             } 
        }
    }
    sort_2(data, way);
}

void mx_algo(t_data *data) {
    int i = 0;
    int j = 0;
    int *temp = (int *)malloc(sizeof(int) * data->size * data->size);
    int **way = (int **)malloc(sizeof(int*) * data->size * data->size);

    for (i = 0; i < data->size * data->size; i ++)
        way[i] = (int *)malloc(sizeof(int ) * (data->size +2));
    
    for (j = 0; j < data->size - 1; j ++) {
        remass(data, way);
        mx_deyxtra(data, way, j, temp);
        sort_mass(data, way);
        for (i = 0; way[i][0] != -1; i++) {
            if (bool_way(data, way[i], temp, j))
                mx_printway(data, way[i]);
        }        
    } 
    mx_free_memory(data, temp, way);
}
