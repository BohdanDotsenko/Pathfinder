#include "path.h"


int main(int argc, char *argv[]) {
	t_data *data = (t_data *)malloc(sizeof(t_data));;
	char *file = mx_file_to_str(argv[1]);

	mx_errors(argc, file, argv);
	mx_parse(file, data);
	mx_algo(data);
	mx_strdel(&file);
	mx_del_strarr(&data->set);
	// system("leaks pathfinder");
	return 0;
}
