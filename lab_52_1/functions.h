#ifndef MY_FILE
#include <stdio.h>
#include <stdlib.h>
#define MY_FILE

#include <string.h>
#include <inttypes.h>

typedef struct student_t 
{
    char surname[26];
    char name[11]; 
    uint32_t marks[4]; 
} student_t;

student_t *read_students(const char *path, int *n);
void save_students(const char *path, student_t *students, int n);
int print_students(const char *path1, const char *path2, const char *substr);
int sort_students(const char *path1, const char *path2);
int remove_students(const char *path);

#endif 