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

//сортировка массива
status_code array_sort(int (*a)[N], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if ((*a)[j] > (*a)[j + 1])
            {
                int t = (*a)[j];
                (*a)[j] = (*a)[j + 1];
                (*a)[j + 1] = t;
            }
        }
    }
    return ok;
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

    err = array_sort(&a, n);
    if (err)
    {
        printf("Net rezultata");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }

    return 0;
}
