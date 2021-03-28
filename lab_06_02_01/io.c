#include "func.h"
#include "struct.h"

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

int read_products(FILE *f, product_t *products, int *count)
{
    int exit_code = SUCCESS;
    int i = 0;
    while (!feof(f))
    {
        if (!fgets(products[i].name, MAX_NAME + 2, f) || exit_code)
            exit_code = INPUT_ERROR;
        if (!exit_code)
            products[i].name[strcspn(products[i].name, "\n")] = '\0';
        if (!exit_code)
            (*count)++;
        if (fscanf(f, "%f\n", &products[i].mass) != 1 || products[i].mass <= 0 || exit_code)
            exit_code = INPUT_ERROR;
        if (!exit_code)
            (*count)++;
        if (fscanf(f, "%f\n", &products[i].volume) != 1 || products[i].volume <= 0 || exit_code)
            exit_code = INPUT_ERROR;
        if (!exit_code)
            (*count)++;
        i++;
    }

    if (*count % 3 || !*count || *count > MAX_STRUCT * 3 || exit_code)
        exit_code = INPUT_ERROR;
    else
        *count /= 3;
    rewind(f);
    return exit_code;
}
