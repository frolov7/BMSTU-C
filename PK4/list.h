#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t 
{
    void* value; 
    struct node_t *next; 
    struct node_t *prev; 
} node_t;

typedef struct dlist_t 
{
    node_t *head; 
    node_t *tail; 
} dlist_t;

dlist_t init_list(); 
void print_forward(dlist_t list, void (*print)(void *value)); 
int add_back(dlist_t *list, void* value);
void insertion_sort(dlist_t *list, int (*compare)(void *value1, void *value2));
void free_list(dlist_t *list, void (*func)(void* value));
#endif