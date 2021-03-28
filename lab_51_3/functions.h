#include <stdio.h>
#ifndef MY_FILE
#include <stdlib.h>
#define MY_FILE

int create_array(const char *path, int n); 
int file_size(FILE *f, long *size);
int print_file(const char *path); 
int get_number_by_pos(FILE *f, int pos); 
int put_number_by_pos(FILE *f, int pos, int value);
int sort_file(const char *path); 

#endif 