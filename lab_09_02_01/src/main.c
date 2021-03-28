#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/func.h"
#include "../inc/io.h"
#include "../inc/struct.h"

int main(int argc, char **argv)
{
    int result = SUCCESS;

    if ((argc != 2 && argc != 3) || !argv[1])
        result = ARGS_ERROR;
    else
    {
        FILE *f = fopen(argv[1], "r");

        if (!f)
            result = INPUT_ERROR;
        else
        {
            product_t *products = NULL;
            int count = 0;

            if (read_products(f, &products, &count))
                result = INPUT_ERROR;
            else
            {
                if (argc == 2)
                {
                    result = sort_in_products(f, products, count); 
                    print(products, count);
                    free_products(products, count);
                }
                else if (argc == 3)
                {
                    result = find_in_products(f, products, count, argv[2]);
                    free_products(products, count);
                }
            }
        }
    }
    
    return result;
}