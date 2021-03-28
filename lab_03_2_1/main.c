#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
#define FALSE 0
#define TRUE 1
//n - stroka, m - stolbec

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

int print_matrix(long a[], long m)
{
    for (long i = 0; i < m; i++)
        printf("%ld\t", a[i]);
    return EXIT_SUCCESS;
}

int alternation(long a[][M], long n, long j, long m)
{
    if ((n == 1 && m == 1) || (n == 1 && m == 2) || (n == 1))
        return FALSE;
    for (long i = 0; i < n - 1; i++) 
        if (a[i][j] * a[i + 1][j] > 0 || a[i][j] == 0 || a[i + 1][j] == 0) 
            return FALSE;
    return TRUE;
}

int main()
{
    long a[N][M];
    long b[N];
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

    printf("\n");
    
    for (long j = 0; j < m; j++)
    {
        if (alternation(a, n, j, m))
            b[j] = 1;
        else 
            b[j] = 0;
    }
    print_matrix(b, m);
    return EXIT_SUCCESS;
}
