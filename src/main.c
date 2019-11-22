#include"libmx.h"

char *mx_file_to_str(const char *file);

// int main(int argc, char *argv[]){
//     char *a = mx_file_to_str(argv[1]);
//     printf("%s", a);
//     return 0;
// }

int **ways(int *all, int dots) {
    int parth_ways[] = {0, 1, 0, 2, 2, 3, 3, 2, 3, 4, 2, 4};
    int longs[] = {11, 10, 5 , 6, 4, 15};
    int **ways = (int **)malloc(sizeof(int *) * dots);
    int k = 0;
    for(int i = 0; i < dots; i++) {
        ways[i] = (int *)malloc(sizeof(int) * dots);
    }
    for(int i = 0; i < dots; i++){
        for(int j = 0; j < dots; j++)
            ways[i][j] = 50000;
    }
    for(int i = 0; i <= dots * 2; i += 2){
        int a = parth_ways[i];
        int b = parth_ways[i + 1];
        ways[a][b] = longs[k];
        ways[b][a] = longs[k];
        k++;
    }
    return ways;
}

 void deyxtra(int **ways, int ind, int longs) {
    int **ways_x = ways;
    char *city[] = {"A", "B", "C", "D", "E"}; 
    char **res_char = NULL;
    res_char = (char **)malloc(sizeof(char *) * 5);
    int index[] = {0, 1, 2, 3, 4};
    for(int i = 0, j = 0; i < 5; i++) {
        res_char[i] = city[ind];
        for(int m = 0, min = 50000; m < 5; m++){
            if (ways_x[ind][m] < min) {
                min = ways_x[ind][m];
                j = m;
            }
        }
        *res_char[i] = *mx_strjoin(res_char[j], " - ");
        // res_char[i] = mx_strjoin(res_char[i], city[j]);
    }
    for(int i = 0; i < 5; i++) {
        if (i != ind)
            printf("%s \n", res_char[i]);
    }
}

int main() {
    int dots = 5;
    int all[] = {1, 2, 3, 4, 5};
    int **a = ways(all, dots);
    for(int i = 0; i < dots; i++){
        for(int j = 0; j < dots; j++)
            printf("%d    ", a[i][j]);
        printf("\n");
    } 
    deyxtra(a, 0, 5);
    return 0;
}
