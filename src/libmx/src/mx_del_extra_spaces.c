#include"libmx.h"

char *mx_del_extra_spaces(const char *str) {
    //int count = 0;
    if (!str)
        return NULL;
    char *result = mx_strtrim(str);
    for(int i = 0; result[i]; i++) {
        if(mx_isspace(result[i])){
            while (mx_isspace(result[i + 1])){
                for(int j = i; result[j - 1]; j++)
                    result[j] = result[j + 1];
            }
            result[i] = ' ';
        }
    }
    return result;
}

// int main() {
//     char *name = "\f  My                         name...                    is              \r Neo           \t\n        ";
//     char *res = mx_del_extra_spaces(name);
//     printf("%s", res);
//     //free(res);
//     //system("leaks a.out");
//     return 0;
// }
