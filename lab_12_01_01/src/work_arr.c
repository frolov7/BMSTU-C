#include "../inc/work_arr.h"

// сравнение целых чисел
int compare_int(const void *a, const void *b) 
{
    const int *pa = (const int *) a;
    const int *pb = (const int *) b;

    return *pa - *pb;
}

void mysort(void *array, size_t num, size_t size, int (*compare)(const void *, const void *)) 
{
    if (num)
    {
        void *tmp = malloc(size); 

        for (size_t i = num - 1; i > 0; i--) 
        {
            int jmax = i;

            for (size_t j = i - 1; j + 1 > 0; j--)
                if (compare((char *) array + jmax * size, (char *) array + j * size) < 0)
                    jmax = j;

            memcpy(tmp, (char *) array + jmax * size, size);
            memcpy((char *) array + jmax * size, (char *) array + i * size, size);
            memcpy((char *) array + i * size, tmp, size);
        }

        free(tmp);
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst) 
{
    int exit_code = 0;

    if (!pb_src || !pe_src || !pb_src || !pe_dst || pb_src > pe_src)
        exit_code = -1;
    else if (!*pb_dst)
    {
        const int *p = pb_src;

        while (p != pe_src && *p >= 0)
            p++;

        int size = p - pb_src; 

        if (size == 0)
            exit_code = -1;
        else
            exit_code = size;
    }
    else
    {
        const int *p = pb_src;

        while (p != pe_src && *p >= 0)
            p++;

        int size = p - pb_src; 

        if (size == 0)
            exit_code = -1;
        else
        {
            if (!*pb_dst)
                exit_code = -1;
            else
            {
                *pe_dst = *pb_dst + size;
                int *dst = *pb_dst;
                for (const int *p2 = pb_src; p2 != p; p2++)
                    *dst++ = *p2;
            }
        }
    }
    
    return exit_code;
}
