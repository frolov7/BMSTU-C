#ifndef IO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/struct.h"
#include "../inc/func.h"
#define IO_H
#define SUCCESS 0
#define INPUT_ERROR -1


void print_product(product_t product);
void print(product_t *products, int count);
int read_products(FILE *f, product_t **products, int *count);

#endif 