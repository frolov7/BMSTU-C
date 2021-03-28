#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "struct.h"

#define ARGS_ERROR 3

void print_product(product_t product);
void print(product_t *products, int count);
int read_products(FILE *f, product_t *products, int *count);

#endif 