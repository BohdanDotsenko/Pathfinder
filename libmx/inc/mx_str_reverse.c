#include"libmx.h"

void mx_str_reverse(char *s) {
    if (!s)
        return;
    int max = mx_strlen(s) - 1;
    int i = 0;
    while(i < max / 2){
        mx_swap_char(&s[i], &s[max - i]);
        i++;
    }

}

// int main() {
//     char a[] = "game over";
//     mx_str_reverse(a);
//     printf("%s", a);
//     return 0;
// }
