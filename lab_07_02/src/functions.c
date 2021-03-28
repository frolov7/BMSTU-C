#include "../inc/functions.h"

// подсчёт количества элементов в файле
int count_elements(FILE *f) 
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);

    int count = -1;
    if (size) 
    {
        count = 0;
        int value;

        fseek(f, 0, SEEK_SET);

        while (!feof(f)) 
        { 
            if (!fscanf(f, "%d", &value)) 
            {
                count = -1;
                break;
            }

            count++;
        }
    }
    return count;
}

int *read_array(FILE *f, int size) 
{
    int *array = (int *) malloc(size * sizeof(int));

    if (array)
        for (int i = 0; i < size; i++)
            fscanf(f, "%d", array + i);

    return array;
}

// вывод в файл
int print_file(const int *begin, const int *end, const char *path) 
{
    int exit_code = 0;
    FILE *f = fopen(path, "w");

    if (!f)
        exit_code = -1;
    else
    {
        for (const int *p = begin; p != end; p++)
            fprintf(f, "%d ", *p);

        fclose(f);
    }
    return exit_code;
}