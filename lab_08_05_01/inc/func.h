#ifndef FUNCS_H
#define FUNCS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../inc/matrix.h"
#include "../inc/struct.h"

void init_matrix(matrix *m);
void free_matrix(matrix *m);

void rem_row(matrix *m, int r);
void rem_col(matrix *m, int c);
void add_row(matrix *m);
void add_col(matrix *m);


#endif