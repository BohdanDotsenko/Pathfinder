#include"pathfinder.h"


char *mx_file_to_str(const char *file) {
    char buf[1];
    char *str;
    int len = 0;
    int fd = open(file, O_RDONLY);
    if (!file) return 
        NULL;
   if (fd < 0) return 
        NULL;
        for(;read(fd, buf, 1); len++);
   close(fd);
   if(len <= 0) return NULL;
   str = mx_strnew(len);
   fd = open(file, O_RDONLY);
   if (fd < 0) return NULL;
   for(int i = 0; read(fd, buf, 1) > 0; i++)
       str[i] = buf[0];
   close(fd);
   return str;
}
