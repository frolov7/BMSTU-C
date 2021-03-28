#include <stdio.h>
#include "my_file.h"

int main()
{
    FILE *f = stdin;
    int count = 0;
    if (local_max(f, &count))
        return -1;
    else
    {
        printf("%d", count);
        return 0;
    }
}