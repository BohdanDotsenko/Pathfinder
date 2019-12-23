#include "pathfinder.h"

int main(int argc, char **argv) {
    char **file = NULL;
    t_data data = mx_parse_file(&file, argc, argv);
    printf("%s", data->cityes);
    return 0;
}
