#include <check.h>
#include <stdio.h>
#include "../inc/func.h"

#ifndef HEAD_UNIT_H
#define HEAD_UNIT_H

int read_products(FILE *f, product_t **products, int *count);
Suite *check_read_func(void);

#endif //HEAD_UNIT_H