#include "func.h"
#include "io.h"
#include "struct.h"

int main(int argc, char **argv)
{
    int exit_code = SUCCESS;

    if ((argc != 2 && argc != 3) || !argv[1])
        exit_code = ARGS_ERROR;
    else
    {
        FILE *f = fopen(argv[1], "r");
        if (!f)
            exit_code = INPUT_ERROR;
        else
        {
            product_t products[MAX_STRUCT];
            int count = 0;
            if (read_products(f, products, &count))
                exit_code = INPUT_ERROR;
            else if (argc == 2)
            {
                exit_code = sort_in_products(f, products, count);
                if (exit_code == SUCCESS)
                    print(products, count);
            }
            else if (argc == 3)
                exit_code = find_in_products(f, products, count, argv[2]);
        }
    }

    return exit_code;
}
