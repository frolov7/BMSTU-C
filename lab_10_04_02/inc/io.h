#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include "garbage_collector.h"
#include "funcs.h"
#include "struct.h"

int read_number(garbage_collector_t *gc, number_t *number); // ввод числа
void print_number(number_t number); // вывод числа
int make_number(garbage_collector_t *gc, int n, number_t *number);
size_t to_number(number_t number);

#endif
