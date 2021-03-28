#ifndef ARR_H
#define ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b); // сравнение целых чисел
void mysort(void *array, size_t num, size_t size, int (*compare)(const void *, const void *)); // сортировка массива методом выбора
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst); // фильтр

#endif
