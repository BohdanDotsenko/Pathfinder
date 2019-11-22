#include"libmx.h"

char *mx_strtrim(const char *str) {
    char *result;
    int start = 0;
    int finish = mx_strlen(str) - 1;

    if(!str)
        return NULL;
    while(mx_isspace(str[start])){
        start++;
    }
    while(mx_isspace(str[finish])){
        finish --;
    }
    result = (char *)malloc(sizeof(char) * (finish - start));
    for(int i = 0; i <= finish - start; i++){
        result[i] = str[i+start];
        result[i + 1] = '\0';
    }
    return result;
}

// int main() {
//     char *name = "\f  My name... is Neo  \t\n ";
//     char *res = mx_strtrim(name);
//     printf("%s\n", res);
//     //free(res);
//     system("leaks a.out");
//     return 0;
// }
