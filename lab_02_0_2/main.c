#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef enum 
{
    ok, 
    er_empty_input_file,
    er_invalid_array_size,
    er_invalid_count_of_elements, 
    er_no_task_answer
} status_code;

status_code array_in(int (*a)[N], int *n)
{
    printf("Vvedite razmer massiva: ");
    if (scanf("%d", n) != 1)
    {
        return er_empty_input_file;
    }
    if (*n < 1 || *n > N)
    {
        return er_invalid_array_size;
    }

    //Ввод массива с подчетом количество введенных
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        count += scanf("%d", &(*a)[i]);
    }

    //Checking end of file
    char tmp;
    int rc = scanf("%c", &tmp);
    if ((count != *n) || (rc != EOF))
    {
        printf("FAIL\n");
        return er_invalid_count_of_elements;
    }
    return ok;
}

//средлее арифметическое элементов
status_code array_mean(int a[N], int n, double *mean)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    *mean = (double)sum / n;
    return ok;
}

//создание нового массива, элементы которого больше среднего арифметического
status_code array_greater_mean(int a[N], int n, int (*b)[N], int *m)
{
    //вычисление среднего
    double mean;
    array_mean(a, n, &mean);
    //форамирование массива
    *m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mean)
        {
            (*b)[*m] = a[i];
            *m = (*m) + 1;
        }
    }
    if (*m == 0) 
    {
        return er_no_task_answer;
    }
    else
    {
        return ok;
    }
}

int main()
{
    int a[N], b[N];
    status_code err;
    int n, m;

    err = array_in(&a, &n);
    if (err)
    {
        printf("Input error.");
        return err;
    }

    err = array_greater_mean(a, n, &b, &m);
    if (err)
    {
        printf("Net podhodyaschix elementov");
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", b[i]);
        }
    }

    return err;
}