#include"libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (str){
        for(int i = 0; i < mx_strlen(str); i++){
            if (str[i] == c)
                return i;
        }
        return -1;
    }
    return -2;
}

// int main(){
//     char *a = "abcdef";
//     char b = 'v';
//     printf("%d", mx_get_char_index(a, b));
//     return 0;
// }
