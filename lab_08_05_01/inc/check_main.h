#include<check.h>
#include<stdio.h>
#include<stdlib.h>
#include"../inc/matrix.h"

#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

int compare_matrix(matrix mat1, matrix mat2);

Suite *add_suite(Suite *s);
Suite *delete_suite(Suite *s);
Suite *grade_suite(Suite *s);

#endif