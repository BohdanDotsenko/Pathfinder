#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *result = mx_strnew(n);
    
    if (!result) {
        return NULL;
    }
    return mx_strncpy(result, s1, n);
}
