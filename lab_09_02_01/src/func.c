#include "../inc/io.h"
#include "../inc/struct.h"

double get_density(product_t product) 
{
    return product.mass / product.volume;
}

void swap(product_t *a, product_t *b)
{
    product_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int sort_in_products(FILE *f, product_t *products, int count)
{
    int is_sorted = 0;
    int i;

    while (!is_sorted)
    {
        is_sorted = 1;

        for (i = 1; i < count; i++)
        {
            if (get_density(products[i]) < get_density(products[i - 1]))
            {
                swap(&products[i], &products[i - 1]);
                is_sorted = 0;
            }
        }
    }

    fclose(f);
    return SUCCESS;
}

int find_in_products(FILE *f, product_t *products, int count, char *string)
{
    int exit_code = SUCCESS;
    if (!strcmp(string, "ALL")) 
    {
        print(products, count);
    }
    else
    {
        int key = 0, i;
        int len = strlen(string);

        for (i = 0; i < count; i++)
        {
            if (!strncmp(products[i].name, string, len))
            {
                key = 1;
                print_product(products[i]);
            }
        }
        fclose(f);
        exit_code = key ? SUCCESS : INPUT_ERROR;
    }
    
    return exit_code;
}

void free_products(product_t *products, int count)
{
    for (int i = 0; i < count; i++)
        free(products[i].name);

    free(products);
}