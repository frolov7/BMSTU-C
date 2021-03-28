#include "../inc/funcs.h"
#include "../inc/struct.h"

int make_number(garbage_collector_t *gc, int n, number_t *number) 
{
    int divider = 2;
    int error = 0;
    number->head = NULL;

    if (n == 0)
    {
        //printf("Number is zero\n");
        error = 1;
    }
    else
    {
        while (n != 1)
        {
            int count = 0;

            while (n != 1 && n % divider == 0) 
            {
                n /= divider;
                count++;
            }

            if (count > 0)
            {
                node_t *node = malloc_gc(gc, sizeof(node_t));

                if (node == NULL)
                {
                    //printf("Memory error\n");
                    error = 1;
                    break;
                }

                node->value = divider;
                node->count = count;
                node->next = number->head;
                number->head = node;
            }

            divider++;
        }
    }

    return error;
}

// ввод числа
int read_number(garbage_collector_t *gc, number_t *number)
{
    int error = 0;
    int n;

    if (!scanf("%d", &n) || n < 1)
    {
        //printf("Invalid number\n");
        error = 1;
    }
    else
    {
        error = make_number(gc, n, number);   
    }

    return error;
}

// вывод числа
void print_number(number_t number)
{
    for (node_t *node = number.head; node; node = node->next)
        printf("%d %d ", node->value, node->count);

    printf("1\n");
}

size_t to_number(number_t number)
{
    size_t result = 1;

    for (node_t *node = number.head; node; node = node->next)
        for (int i = 0; i < node->count; i++)
            result *= node->value;

    return result;
}

void add_value(number_t *number, node_t **prev, node_t *node)
{
    node->next = NULL;

    if (number->head == NULL)
    {
        number->head = node;
    }
    else
    {
        (*prev)->next = node;
    }

    *prev = node;
}