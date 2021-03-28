#ifndef FUNCS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/struct.h"
#define FUNCS_H
#define SUCCESS 0
#define ARGS_ERROR 1
#define INPUT_ERROR -1

double get_density(product_t product);
void swap(product_t *a, product_t *b);
int sort_in_products(FILE *f, product_t *products, int count);
int find_in_products(FILE *f, product_t *products, int count, char *string);
void free_products(product_t *products, int count);

#endif 