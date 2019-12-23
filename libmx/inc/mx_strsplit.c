#include"libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) {
        return NULL;
    }
    int size_arr = mx_count_words(s, c);
    int counter = 0;
    char **result = malloc(sizeof(char *) * (size_arr + 1));
    int len = mx_strlen(s);
    int index = 0;
    if (size_arr == 1) {
        result[0] = mx_strdup(s);
        result[1] = NULL;
        return result;
    }
    for (int i = 0; i < len; i++) {
        index = mx_get_char_index(s, c);
        index = index == -1 ? mx_strlen(s) : index;
        if (index) {
            result[counter] = mx_strndup(s, index);
            s += mx_strlen(result[counter]) - 1;
            i += mx_strlen(result[counter]) - 1;
            counter++;
        }
        s++;
    } 
    result[size_arr] = NULL;
    return result;
}

// int main() {
//     char *s1 = "**Good bye,**Mr.*Anderson.****";
//     char **arr1 = mx_strsplit(s1, '*');  // arr = ["Good bye,", "Mr.", "Anderson."]
//     mx_print_strarr(arr1, " ");
//     char *s2 = "     Knock, knock,    Neo.   ";
//     char **arr2 = mx_strsplit(s2, ' ');  // arr = ["Knock,", "knock,", "Neo."]
//     mx_print_strarr(arr2, " ");
 
//     return 0;
// }

