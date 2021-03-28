#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10

int input_matrix(int a[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
                return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int print_matrix(int a[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}


int matrix_processing(int a[N][M], int n, int m, int *max)
{
    int found = 0; 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (((i + j) > n - 1) && (abs(a[i][j]) % 10 == 5))
            {
                if (found == 0) 
                {
                    found = 1; 
                    *max = a[i][j]; 
                }
                else if (a[i][j] > *max) 
                {
                    *max = a[i][j];
                }
            }
        }
    }
    if (found == 1)
    {
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}

int main()
{
    int a[N][M];
    int n, m;

    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    else if (n < 1 || n > N)
        return EXIT_FAILURE;

    if (scanf("%d", &m) != 1)
        return EXIT_FAILURE;
    else if (m < 1 || m > M || m != n)
        return EXIT_FAILURE;

    if (input_matrix(a, n, m))
       return EXIT_FAILURE;

    int max = 0;
    if (matrix_processing(a, n, m, &max))
    {
        return EXIT_FAILURE;
    }
    else
    {
        printf("%d", max);
    }

    return EXIT_SUCCESS;
}