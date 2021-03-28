#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

typedef enum 
{
    ok, 
    er_empty_input_file,
    er_invalid_array_size,
    er_no_task_answer,
    er_invalid_count_of_elements
} status_code;

status_code array_in(int (*a)[N*2], int *n)
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

//получение положительного числа, записанного наоборот
int reverse_number(int n)
{
    int digits[10]; //массив цифр
    int m = 0; //количество цифр
    while (n != 0)
    {
        digits[m] = n % 10;
        m++;
        n = n / 10;
    }
    //получаем число наоборот
    int rn = 0;
    for (int i = 0; i < m; i++)
    {
        rn += digits[i] * round(pow(10, m - 1 - i));
    }
    return rn;
}

//вставка после положительных
status_code array_insert(int (*a)[N*2], int *n)
{
    int m = (*n);
    int i = 0, k = 0;
    while (k != m)
    {
        if ((*a)[i] > 0)
        {
            *n = (*n) + 1; //колчичество элементов возрастет на 1
            //сдвигаем элементы справа на 1 вправо, освобождая место
            for (int j = (*n) - 1; j >= i + 2; j--)
            {
                (*a)[j] = (*a)[j - 1];
            }
            (*a)[i + 1] = reverse_number((*a)[i]);
            i += 2;
        }
        else
        {
            i += 1;
        }
        k++;
    }
    return ok;
}

int main()
{
    int a[N*2];
    status_code err;
    int n;

    err = array_in(&a, &n);
    if (err)
    {
        printf("Input error.");
        return err;
    }

    err = array_insert(&a, &n);
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
