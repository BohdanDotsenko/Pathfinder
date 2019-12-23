#include<stdio.h>

void mx_printstr(const char *s);
void mx_printchar(char c);

void mx_print_strarr(char **arr, const char *delim) {
	if (delim && arr) {
		for(int i = 0; arr[i] != NULL; i++) {
			mx_printstr(arr[i]);
			mx_printstr(delim);
		}
	mx_printchar('\n');
	}
}

