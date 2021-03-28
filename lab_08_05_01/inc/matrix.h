#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../inc/func.h"
#include "../inc/struct.h"

void identy_matrix(matrix *m);
void multiply_matrix(const matrix *l, const matrix *r, matrix *m);
void power_matrix(matrix *m, int p);
int min_matrix(const matrix *m);

void matrix_to_square(matrix *m);
void matrix_inflate(matrix *m, int s);

#endif