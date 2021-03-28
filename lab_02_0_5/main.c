#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

typedef enum 
{
    ok, 
    er_empty_input_file,
    er_invalid_count_of_elements,
    er_invalid_array_size,
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

//поиск максимального
//передаем массив и указатель на элемент за последним
status_code array_eval(int x[N], int *l, int *max)
{
    if (x == l)
    {
        return er_no_task_answer;
    }
    else
    {
        int n = l - x; //размер массива
        //определение указателЯ на центральный элемент (до которого будет цикл)
		//int* h = x + (int)ceil(n/2);
        int *h;
        if (n % 2 == 0)
        {
            h = x + (int)ceil(n / 2);
        }
        else
        {
            h = x + (int)(n / 2) + 1;
        }
        *max = *x + *(l - 1);
        for (int *i = x; i < h; i++)
        {
            int m = *i + *(x + (l - 1 - i)); //сумма элементов с двух противоположных сторон
            if (m > *max)
            {
                *max = m;
            }
        }
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

    int max;
    err = array_eval(a, &a[n], &max);
    if (err)
    {
        printf("Net rezultata");
    }
    else
    {
        printf("%d ", max);
    }

    return err;
}
