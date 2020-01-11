#include "path.h"

static void check_island12(char *island1, char *island2, char *dist, int nline) {
	char *index = NULL;

	if (mx_strcmp(island1,island2) == 0 && mx_atoi(dist) != 0) {
		nline++;
		index = mx_itoa(nline);
		mx_printerr("error: line ");
		mx_printerr(index);
		mx_printerr(" is not valid\n");
		exit(EXIT_FAILURE);
	}
}

static void mx_linearr(char *line, char **island1, char **island2, char **dist) {
	int i = 0;
	char *str = line;

	while(str[i] != '-')
		i++;
	*island1 = mx_strndup(str, i);
	str += i + 1;
	i = 0;
	while(str[i] != ',')
		i++;
	*island2 = mx_strndup(str, i);
	str += i + 1;
	i = 0;
	while(str[i] != '\0')
		i++;
	*dist = mx_strndup(str, i);
}

static void mx_fill_islands(char ***arr, char **lines, int line) {
	char **ar = *arr;
	char *island1 = NULL;
	char *island2 = NULL;
	char *dist = NULL;

	while(lines[line]) {
		mx_linearr(lines[line], &island1, &island2, &dist);
		check_island12(island1, island2, dist, line);
		*ar = mx_strdup(island1);
		ar++;
		mx_strdel(&island1);
		*ar = mx_strdup(island2);
		ar++;
		mx_strdel(&island2);
		*ar = mx_strdup(dist);
		line++, arr++;
		mx_strdel(&dist);
	}
	*ar = NULL;
}

void mx_arr(char **lines, char ***arr){
	int line = 1;

	while (lines[line]){
		line++;
	}
	*arr = (char **)malloc((line * 3 + 1) * sizeof(char *));
	mx_fill_islands(&(*arr), lines, 1);
}
