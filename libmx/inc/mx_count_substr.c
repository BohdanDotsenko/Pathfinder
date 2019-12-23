#include"libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    if (!str || !sub)
        return -1;
    for(char *res = mx_strstr(str, sub); res != NULL; res = mx_strstr(res + 1, sub))
        count++;
    return count;
}

// int main() {
//     char *a = "yo yo yo Neo";
//     char *b = "yo";
//     printf("%d", mx_count_substr(a, b));
//     return 0;
// }
