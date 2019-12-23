#include"pathfinder.h"

data mx_reading_file(&file, int argc, char **argv){
    char *input = NULL;
    data *data = NULL;
    int count;

    mx_check_open(argc, argv);
    input = mx_file_to_str(argc, argv);
    *file = mx_file_to_str(file, '\n');
    mx_strdel(&input);
    mx_check_first(*file[0]);
    data = mx_push_data(*file);
    mx_check_lines(&data, *file);
    count = mx_parse(&data, *file);
    if (count != data->cityes)
        mx_print_error();
    mx_parse_matrix(&data, *file)
    return data;
}

void mx_check_open(int argc, char **argv) {
    int file = 0;
    char buf;

    if (argc != 2)
        mx_print_error(ERROR_USAGE, NULL, NULL);
    if ((file = open(argv[1], O_RDONLY)) == -1)
        mx_print_error(ERROR_FILE, argv[1], ERROR_EXIST);
    if (read(file, &buf, 1) == 0)
        mx_print_error(ERROR_FILE, argv[1], ERROR_EMPTY);
    close(file);
}
