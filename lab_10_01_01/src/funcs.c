#include "../inc/list.h"
#include "../inc/funcs.h"

// извлечение элемента из начала списка
void *pop_front(node_t **head) 
{
    void *data = NULL;

    if (head && *head) 
    {
        node_t *node = *head; 
        data = node->data; 
        *head = node->next;
        free(node);
    }
    return data; 
}

// извлечение элемента из конца списка
void *pop_back(node_t **head) 
{
    void *data = NULL;
    if (head && *head)
    { 
        if ((*head)->next == NULL) 
        {
            data = (*head)->data; 
            free(*head); 
            *head = NULL; 
        }
        else
        {
            node_t *prev = NULL;
            node_t *node = *head; 

            while (node->next) 
            {
                prev = node;
                node = node->next;
            }

            data = node->data;
            free(node);
            prev->next = NULL;
        }
    }
    return data;
}

// перестановка элементов списка в обратном порядке
node_t *reverse(node_t *head) 
{
    if (head)
    {
        node_t *node = head;

        while (node->next) 
        {
            node_t *next = node->next; 
            node->next = next->next;
            next->next = head;
            head = next; 
        }
    }
    return head; 
}

// вставка в отсортированный список
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *)) 
{
    if (*head == NULL || comparator((*head)->data, element->data) >= 0) 
    {
        element->next = *head; 
        *head = element; 
    }
    else 
    {
        node_t *node = *head;

        while (node->next && comparator(node->next->data, element->data) < 0)
            node = node->next;

        element->next = node->next;
        node->next = element;
    }
}

// сортировка списка
node_t *sort(node_t *head, int (*comparator)(const void *, const void *)) 
{
    node_t *node = head; 
    head = NULL;

    while (node) 
    { 
        node_t *next = node->next;
        sorted_insert(&head, node, comparator); 
        node = next;
    }
    
    return head;
}