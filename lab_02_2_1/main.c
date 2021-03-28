#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef enum 
{
    ok, 
    er_empty_input_file,
    er_invalid_array_size,
    er_no_task_answer,
    er_invalid_count_of_elements
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
        return er_invalid_count_of_elements;
    }
    return ok;
}

//средлее арифметическое отрицательных элементов
status_code mean_negative(int a[N], int n, double *mean)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            count += 1;
            sum += a[i];
        }
    }
    if (count == 0)
    {
        *mean = 0;
        return er_no_task_answer;
    }
    else
    {
        *mean = (double)sum / count;
        return ok;
    }
}

int main()
{
    int a[N];
    status_code err;
    int n;

    err = array_in(&a, &n);
    if (err)
    {
        printf("Input error.");
        return err;
    }

    double mean;
    err = mean_negative(a, n, &mean);
    if (err)
    {
        printf("Net otricatel'nyx.");
    }
    else
    {
        printf("%lf", mean);
    }

    return err;
}