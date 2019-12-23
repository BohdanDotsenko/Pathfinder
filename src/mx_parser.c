#include"pathfinder.h"

static void mx_check_open(int argc, char **argv);
static void mx_check_first_line(char *line);
static t_data *mx_create_pf_variables(char **file);

t_data mx_reading_file(char ***file, int argc, char **argv){
    char *input = NULL;
    t_data *data = NULL;
    int count;

    mx_check_open(argc, argv);
    input = mx_file_to_str(argv[1]);
    *file = mx_strsplit(input, '\n');
    mx_strdel(&input);
    mx_check_first(*file[0]);
    data = mx_push_data(*file);
    mx_check_lines(data, *file);
    count = mx_parse_str(&data, *file);
    if (count != data->cityes)
        mx_print_error(ERROR_LOGIC, NULL, NULL);
    mx_parse_matrix(&data, *file);
    return *data;
}

static void mx_check_open(int argc, char **argv) {
    int fd = 0;
    char buf;

    if (argc != 2)
        mx_print_error(ERROR_USAGE, NULL, NULL);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        mx_print_error(ERROR_FILE, argv[1], ERROR_EXIST);
    if (read(fd, &buf, 1) == 0)
        mx_print_error(ERROR_FILE, argv[1], ERROR_EMPTY);
    close(fd);
}

static void mx_check_first_line(char *line) {
    int len = mx_strlen(line);

    for (int i = 0; i < len; i++) {
        if (line[i] < 48 || line[i] > 57)
            mx_print_error(ERROR_LINE, "1", ERROR_INVALID);
    }
}
