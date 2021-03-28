#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv) 
{
    if (argc == 4 && !strcmp(argv[1], "sb"))
        return sort_students(argv[2], argv[3]);

    if (argc == 5 && !strcmp(argv[1], "fb"))
        return print_students(argv[2], argv[3], argv[4]);
    
    if (argc == 3 && !strcmp(argv[1], "db"))
        return remove_students(argv[2]);

    return 53;
}