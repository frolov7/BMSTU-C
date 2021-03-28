#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

bool is_prime(int n)
{
    if (n <= 1) 
    {
        return false;
    }
    else
    {
        //printf("%d => %d", n, ceil(n / 2));
        bool prime = true;
        for (int d = 2; d <= ceil(n / 2); d++)
        {
            if (n % d == 0)
            {
                //printf("%d\n", d);
                prime = false;
                break;
            }
        }
        return prime;
    }
}


int get_primes(int a[N][M], int n, int m, int b[N*M], int *k)
{
    *k = 0; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (is_prime(a[i][j])) 
            {
                b[*k] = a[i][j]; 
                *k += 1;
            }
        }
    }

    if (*k == 0) 
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

void reverse(int b[N*M], int k)
{
    for (int i = 0; i < ceil(k / 2); i++)
    {
        int t = b[i];
        b[i] = b[k - 1 - i];
        b[k - 1 - i] = t;
    }
}


void insert_array(int a[N][M], int n, int m, int b[N*M], int k)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (is_prime(a[i][j]))
            {
                a[i][j] = b[c];
                c ++;
            }
        }
    }
}

int main()
{
    int a[N][M];
    int n, m;
    int b[N*M]; 
    int k;

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

    if (get_primes(a, n, m, b, &k))
    {
        print_matrix(a, n, m);
        return EXIT_FAILURE;
    }
    else
    {
        reverse(b, k);
        insert_array(a, n, m, b, k);
        print_matrix(a, n, m);
    }
    return EXIT_SUCCESS;
}
