#include <stdio.h>
#include <stdlib.h>
#define N 20
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
int sum_digits(int n)
{
    n = abs(n);
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void insert_line(int a[N][M], int *n, int m, int k)
{
    for (int i = *n - 1; i >= k; i--)
    {
        for (int j = 0; j < m; j++)
        {
            a[i + 1][j] = a[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        a[k][j] = -1;
    }
    *n = *n + 1; 
}

void matrix_processing(int a[N][M], int *n, int m)
{
    int i = 0;
    while (i < *n)
    {
        int cnt = 0; 
        for (int j = 0; j < m; j++)
        {
            if (sum_digits(a[i][j]) % 2 != 0) 
            {
                cnt++; //+1
            }
        }
        if (cnt >= 2) 
        {
            insert_line(a, n, m, i);
            i += 2; 
        }
        else
        {
            i++;
        }
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
    else if (m < 1 || m > M)
        return EXIT_FAILURE;

    if (input_matrix(a, n, m))
       return EXIT_FAILURE;

    matrix_processing(a, &n, m);
    print_matrix(a, n, m);

    return EXIT_SUCCESS;
}