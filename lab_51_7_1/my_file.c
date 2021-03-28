#include <stdio.h>
#include "my_file.h"

int local_max(FILE *f, int *count) 
{
    int left, center, right;
    int k = 0;
    
    if (fscanf(f, "%d", &left) == 1)
    {
        k++;
        while (fscanf(f, "%d", &right) == 1)
        {   
            if (k < 2)
                center = right;
            else
            {
                if (center > left && center > right)
                    *count += 1;
                left = center;
                center = right;
            }
            k++;   
        }
    }
    else
        return -1;
    if (k > 2)
        return 0;
    else
        return -1;
    return 0;
}