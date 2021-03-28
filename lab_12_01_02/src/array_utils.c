#include "../inc/array_utils.h"
#include <math.h>



void cycle_shift(int *arr, size_t len, size_t k)
{
    if (len)
    {
        k %= len;
        int *t = malloc(k * sizeof(int));
        for (size_t i = 0; i < k; i++)
            t[i] = arr[i];

        for (size_t i = 0; i < len - k; i++)
            arr[i] = arr[i + k];

        for (size_t i = 0; i < k; i++)
            arr[len - k + i] = t[i];

        free(t);
    }
}
size_t copy_squares(const int *arr, size_t len, int *dst)
{
    size_t pt = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] >= 0)
        {
            int rt = sqrt(arr[i]);
            if (rt * rt == arr[i])
            {
                if (dst)
                    dst[pt] = arr[i];
                pt++;
            }
        }
    }
    return pt;
}
