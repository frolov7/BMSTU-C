#include<check.h>
#include<stdio.h>

#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

int compare_arrs(int *arr1, int len1, int *arr2, int len2);

Suite *sort_suite(Suite *s);
Suite *key_suite(Suite *s);

#endif
