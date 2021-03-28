#include<stdio.h>

int calculation_func(int n)
{
    int i = 2;
    while (1)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            break;
        }
        i++;
    }
    return i;
}


int main()
{
    int n;

    if (scanf("%d", &n) == 1)
    {
        if (n <= 0)
        {
            return 2;
        }
        if (n == 1)
        {
            return 0;
        }
        do
        {
            n = n / calculation_func(n);
        }while (n != 1);
    }
    else
    {
        printf("Not integer");
        return 1;
    }
    return 0;
}
