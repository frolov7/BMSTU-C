#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/funcs.h"

int push_front(node_t **head, void *data); 
void print_list(FILE *f, node_t *head, void (*print_node)(FILE *f, void *data)); 
void iterate_list(node_t *head, void (*action)(void *data)); 
void free_list(node_t **head);

#endif