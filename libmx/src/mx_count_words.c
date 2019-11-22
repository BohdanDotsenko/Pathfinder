#include"libmx.h"

int mx_count_words(const char *str, char c) {
    int count = 0;
    if (!str)
        return -1;
    if ((str[0] != c) && (str[1] != c) && (str[0] != '\0'))
        count++;
    for(int i = 1; i < mx_strlen(str) - 2; i++) {
        if ((str[i] == c) && (str[i + 1] != c) 
            && (str[i] != '\0') && (str[i + 1] != '\0'))
            count++;
    }
    return count;
}

// int main() {
//     char *str = "  follow  *   the  white rabbit ";
//     char a = '*';
//     char b = ' ';
//     printf("%d \n", mx_count_words(str, a)); //returns 2
//     printf("%d\n", mx_count_words(str, b)); //returns 5
//     printf("%d\n", mx_count_words(NULL, b)); //returns -1
//     return 0;
// }
