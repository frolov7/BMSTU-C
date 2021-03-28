#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv) 
{
    if (argc == 4 && !strcmp(argv[1], "c")) 
    {
        int number;
        if (!sscanf(argv[2], "%d", &number))
            return -1;

        create_array(argv[3], number);
        return 0;
    }

    if (argc == 3 && !strcmp(argv[1], "p"))
        return print_file(argv[2]);

    if (argc == 3 && !strcmp(argv[1], "s"))
        return sort_file(argv[2]);

    return -1;
}