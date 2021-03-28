#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct student_t 
{
    char *name; 
    int age; 
    dlist_t marks; 
} student_t;

char* read_string(const char *message); 
int is_integer(char *s); 
int read_integer(const char *message); 

student_t* read_student(); 
void print_student(void *student); 
int compare(void *student1, void *student2);
void free_student(void *student);

#endif