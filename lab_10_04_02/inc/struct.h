#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include "garbage_collector.h"
#include "io.h"
#include "funcs.h"

// элемент числа (списка)
typedef struct node_t
{
    int value; // коэффициент
    int count; // количество
    struct node_t *next; // указатель на следующий элемент
} node_t;

// полином (список)
typedef struct number_t
{
    node_t *head; // начало списка
} number_t;

#endif