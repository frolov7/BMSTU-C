#include "../inc/list.h"
#include "../inc/funcs.h"

// добавление в начао списка
int push_front(node_t **head, void *data) 
{
    int rc = 0;
    node_t *node = (node_t *) malloc(sizeof(node_t));

    if (node == NULL) 
        rc = -1; 
    else
    {
        node->data = data; 
        node->next = *head; 
        *head = node;  
    }

    return rc; 
}

// вывод списка
void print_list(FILE *f, node_t *head, void (*print_node)(FILE *f, void *data)) 
{
    for (node_t *node = head; node; node = node->next)
        print_node(f, node->data);
}

void iterate_list(node_t *head, void (*action)(void *data)) 
{
    for (node_t *node = head; node; node = node->next)
        action(node->data);
}

// освобождение памяти из-под списка
void free_list(node_t **head) 
{
    while (*head) 
    {
        node_t *tmp = *head; 
        *head = (*head)->next; 
        free(tmp); 
    }
}