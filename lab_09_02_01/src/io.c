#include "../inc/func.h"
#include "../inc/struct.h"

void print_product(product_t product)
{
    printf("%s\n%f\n%f\n", product.name, product.mass, product.volume);
}

void print(product_t *products, int count)
{
    int i;
    for (i = 0; i < count; i++)
        print_product(products[i]);
}

char *read_string(FILE *f) 
{
    int size = 0; 
    int capacity = 1;
    char *s = (char *) malloc(capacity * sizeof(char));
    if (s)
    {
        for (char c = fgetc(f); c != '\n' && c != EOF; c = fgetc(f)) 
        {
            s[size++] = c;

            if (size >= capacity) 
            { 
                capacity *= 2;
                s = (char *) realloc(s, capacity * sizeof(char));

                if (!s)
                    break;
            }
        }
        if (s) 
            s[size] = '\0'; 
    }
    return s; 
}

int read_product(FILE *f, product_t *product)
{
    int exit_code = SUCCESS;

    product->name = read_string(f);

    if (product->name == NULL)
        exit_code = INPUT_ERROR;
    else if (fscanf(f, "%f\n", &product->mass) != 1 || product->mass <= 0)
    {
        free(product->name);
        exit_code = INPUT_ERROR;
    }
    else if (fscanf(f, "%f\n", &product->volume) != 1 || product->volume <= 0)
    {
        free(product->name);
        exit_code = INPUT_ERROR;
    }

    return exit_code;
}

int read_products(FILE *f, product_t **products, int *count)
{
    int exit_code = SUCCESS;

    *products = (product_t *) malloc(sizeof(product_t));
    *count = 0;
    int capacity = 1;

    while (!feof(f))
    {
        if (read_product(f, &(*products)[*count]) == INPUT_ERROR)
        {
            free_products(*products, *count);
            exit_code = INPUT_ERROR;
            break;
        }

        (*count)++;

        if (*count >= capacity)
        {
            capacity *= 2;
            *products = (product_t *) realloc(*products, capacity * sizeof(product_t));
        }
    }

    if (exit_code == SUCCESS)
    {
        if (*count == 0) 
        {
            free(*products);
            exit_code = INPUT_ERROR;
        }
        else
        {
            rewind(f);
            *products = (product_t *) realloc(*products, *count * sizeof(product_t));   
        }
    }

    return exit_code;
}
