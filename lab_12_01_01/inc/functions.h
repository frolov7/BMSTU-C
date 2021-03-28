#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_elements(FILE *f); // подсчёт количества элементов в файле
int *read_array(FILE *f, int size); // ввод массива с выделением памяти

int print_file(const int *begin, const int *end, const char *path); // вывод в файл

#endif