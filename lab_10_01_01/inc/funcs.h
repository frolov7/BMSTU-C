#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/list.h"

typedef struct node 
{
    void *data;
    struct node *next;
} node_t;

void *pop_front(node_t **head); 
void *pop_back(node_t **head); 
node_t *reverse(node_t *head); 
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *)); 

#endif