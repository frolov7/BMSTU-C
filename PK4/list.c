#include "list.h"

dlist_t init_list() {
    dlist_t list;
    list.head = NULL;
    list.tail = NULL; 

    return list; 
}

void print_forward(dlist_t list, void (*print)(void *value)) 
{
    if (list.head == NULL) 
    {
        printf("empty\n");
        return; 
    }
 
    for (node_t *node = list.head; node; node = node->next)
        print(node->value); 
}

// добавление в конец списка
int add_back(dlist_t *list, void* value) 
{
    node_t *node = (node_t*) malloc(sizeof(node_t)); 

    if (node == NULL)
        return -1;

    node->value = value; 
    node->next = NULL; 
    node->prev = list->tail; 

    if (list->head == NULL) 
    { 
        list->head = node; 
    }
    else 
    {
        list->tail->next = node; 
    }

    list->tail = node; 
    return 0;
}

void insertion_sort(dlist_t *list, int (*compare)(void *value1, void *value2)) 
{
    node_t *node = list->head->next;

    while (node) 
    {
        node_t *tmp = node;
        node_t *prev = node->prev;
        node_t *next = node->next;

        prev->next = next;

        if (node != list->tail) 
        {
            next->prev = prev;
        }
        else 
        {
            list->tail = prev;
        }

        node_t *elem = prev;

        while (elem && compare(elem->value, tmp->value) > 0)
            elem = elem->prev;

        node->prev = elem;

        if (elem == NULL) 
        { 
            node->next = list->head;
            list->head->prev = node;
            list->head = node;
        }
        else 
        {
            if (elem == list->tail) 
            { 
                list->tail = node; 
            }
            else 
            { 
                node->next = elem->next;
                elem->next->prev = node;
            }

            elem->next = node;
        }

        node = tmp->next; 
    }
}

void free_list(dlist_t *list, void (*func)(void* value)) 
{
    while (list->head) 
    {
        func(list->head->value);
        node_t *tmp = list->head; 
        list->head = list->head->next; 
        free(tmp); 
    }
}
