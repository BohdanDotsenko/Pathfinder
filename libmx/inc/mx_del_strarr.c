#include"libmx.h"

void mx_del_strarr(char ***arr) { 
    char **delstr = *arr;
    while(delstr++) {
        mx_strdel(delstr);
    }
    mx_strdel(*arr);
}

// int main() {
//     char **arr = (char **) malloc(3 * sizeof(char *));
//     for (int i = 0; i < 3; i++)
//         arr[i] = mx_strnew(3);
//     mx_del_strarr(&arr);
   
//     system("leaks a.out");
//     return 0;
// }
