#include "../inc/io.h"
#include "../inc/funcs.h"
#include "../inc/struct.h"
#include "../inc/garbage_collector.h"

int main()
{   
    garbage_collector_t gc = init_gc();
    char command[100];

    number_t number, n1, n2;
    int was_error = 0;

    scanf("%[^\n]", command);

    if (!strcmp("out", command))
    {
        if (!read_number(&gc, &number))
        {
            print_number(number);
        }
        else
        {
            was_error = 1;
        }
    }
    else if (!strcmp("mul", command))
    {
        if (!read_number(&gc, &n1) && !read_number(&gc, &n2))
        {
            number = multiply(n1, n2);

            if (number.head)
            {
                print_number(number);
            }
            else
            {
                was_error = 1;
            }
        }
        else
        {
            was_error = 1;
        }
    }
    else if (!strcmp("sqr", command))
    {
        if (!read_number(&gc, &number))
        {
            square(number);
            print_number(number);
        }
        else
        {
            was_error = 1;
        }
    }
    else if (!strcmp("div", command))
    {
        if (!read_number(&gc, &n1) && !read_number(&gc, &n2))
        {
            number = divide(&gc, n1, n2);

            if (number.head) 
            {
                print_number(number);
            }
            else
            {
                was_error = 1;
            }
        }
        else
        {
            was_error = 1;
        }
    }   
    else
    {
        was_error = 1;
    }

    free_gc(&gc);

    return was_error ? -1 : 0;
}