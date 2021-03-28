#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "struct.h"

#define SUCCESS 0
#define INPUT_ERROR 2

double get_density(product_t product);
void swap(product_t *a, product_t *b);
int sort_in_products(FILE *f, product_t *products, int count);
int find_in_products(FILE *f, product_t *products, int count, char *string);

#endif 