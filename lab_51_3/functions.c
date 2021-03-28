#include <stdio.h>
#include "functions.h"

int create_array(const char *path, int n) 
{
    FILE *f = fopen(path, "wb"); 
    if (n < 1)
<<<<<<< HEAD
        return -1;
=======
		return -1;
>>>>>>> 4b5b9617dccef359d506cbcf41f872decfe0778f
    if (!f)
        return -1;
    for (int i = 0; i < n; i++) 
    {
        int value = rand() % (n * 2);
        if (fwrite(&value, sizeof(int), 1, f) != 1)
            return -1;
    }
    return 0;
    
    fclose(f); 
}

int file_size(FILE *f, long *size)
{
    int sz;
    if (fseek(f, 0, SEEK_END))
        return -1;

    sz = ftell(f);
    
    if (sz < 0)
        return -1;
    
    *size = ftell(f) / sizeof(int);
    fseek(f, 0, SEEK_SET);
    return 0;
}

int print_file(const char *path) 
{
    FILE *f = fopen(path, "rb"); 
    long size;
    if (file_size(f, &size))
    {
        fclose(f);
        return -1;
    }

    if (size == 0) 
    {
        fclose(f);
        return -1;
    }

    int value;
    while (fread(&value, sizeof(int), 1, f))
        printf("%d\n", value); 

    fclose(f); 
    return 0;
}

int get_number_by_pos(FILE *f, int pos) 
{
    int value;
    fseek(f, pos * sizeof(int), SEEK_SET);
    fread(&value, sizeof(value), 1, f);
    return value;
}

int put_number_by_pos(FILE *f, int pos, int value) 
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    fwrite(&value, sizeof(value), 1, f);
    return 0;
}

int sort_file(const char *path) 
{
    FILE *f = fopen(path, "rb+"); 

    if (!f)
        return -1;

    fseek(f, 0, SEEK_END);
    long size = ftell(f) / sizeof(int);

    if (size == 0)
        return -1;
    
    for (int i = 1; i < size; i++) 
    {
        int tmp = get_number_by_pos(f, i);
        int j = i;

        while (j > 0 && tmp < get_number_by_pos(f, j - 1)) 
        {
            put_number_by_pos(f, j, get_number_by_pos(f, j - 1));
            j--;
        }

        put_number_by_pos(f, j, tmp); 
    }

    fclose(f);
    return 0;
}