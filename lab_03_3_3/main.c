#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define FALSE 0
#define TRUE 1

int input_matrix(long a[][M], long n, long m)
{
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < m; j++)
            if (scanf("%ld", &a[i][j]) != 1)
                return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int min_elem(long a[N][M], long m, long i)
{
    long min = a[i][0];
    size_t j = 1;
    
    while (j < m) 
    {
        if (a[i][j] < min)
            min = a[i][j];
        j++;
    }
    return min;
}

int sort(long a[N][M], long n, long m)
{
    long tmp;
    int flag = FALSE;
    while (flag != TRUE) 
    {
        flag = TRUE;
        for (long i = 0; i < n - 1; i++) 
        {
            if (min_elem(a, m, i) < (min_elem(a, m, i + 1))) 
            {
                flag = FALSE;
                for (long j = 0; j < m; j++) 
                {
                    tmp = a[i][j];
                    a[i][j] = a[i + 1][j];
                    a[i + 1][j] = tmp;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}

int main()
{
    long a[N][M];
    long n, m;
    
    if (scanf("%ld", &n) != 1)
        return EXIT_FAILURE;
    else if (n < 1 || n > N)
        return EXIT_FAILURE;

    if (scanf("%ld", &m) != 1)
        return EXIT_FAILURE;
    else if (m < 1 || m > M)
        return EXIT_FAILURE;

    if (input_matrix(a, n, m))
        return EXIT_FAILURE;
    else 
    {
        sort(a, n, m);
        for (long i = 0; i < n; i++) 
        {
            printf("\n");
            for (long j = 0; j < m; j++) 
            {
                printf("%ld ", a[i][j]);
            }
        }
        return EXIT_SUCCESS;
    }
}
