#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "garbage_collector.h"
#include "io.h"
#include "struct.h"

void add_value(number_t *number, node_t **prev, node_t *node);
number_t multiply(number_t a, number_t b); // произведение чисел
number_t divide(garbage_collector_t *gc, number_t a, number_t b); // целочисленное деление чисел
void square(number_t number); // возведение в квадрат

#endif