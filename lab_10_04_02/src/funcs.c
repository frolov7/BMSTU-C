#include "../inc/io.h"
#include "../inc/struct.h"

// произведение чисел
number_t multiply(number_t a, number_t b)
{
    number_t result;

    result.head = NULL;
    node_t *prev = NULL;

    node_t *node_a = a.head;
    node_t *node_b = b.head;

    while (node_a && node_b) 
    {
        node_t *next_a = node_a->next;
        node_t *next_b = node_b->next;

        if (node_a->value > node_b->value) 
        {
            add_value(&result, &prev, node_a);
            node_a = next_a;
        }
        else if (node_a->value < node_b->value) 
        {
            add_value(&result, &prev, node_b);
            node_b = next_b;
        }
        else 
        {
            node_a->count += node_b->count;
            add_value(&result, &prev, node_a);
            node_a = next_a;
            node_b = next_b;
        }        
    }

    while (node_a) 
    {
        node_t *next = node_a->next;
        add_value(&result, &prev, node_a);
        node_a = next;
    }

    while (node_b) 
    {
        node_t *next = node_b->next;
        add_value(&result, &prev, node_b);
        node_b = next;
    }

    return result;
}

// целочисленное деление чисел
number_t divide(garbage_collector_t *gc, number_t a, number_t b) 
{
    size_t na = to_number(a);
    size_t nb = to_number(b);

    number_t result;
    make_number(gc, na / nb, &result);
    return result;
}

// возведение в квадрат
void square(number_t number)
{
    for (node_t *node = number.head; node; node = node->next)
        node->count *= 2;
}
