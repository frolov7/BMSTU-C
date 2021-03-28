#include "function.h"

int average(const char *path, double *avg) 
{
    FILE *f = fopen(path, "r"); 

    if (!f)
        return -1; 

    int count = 0;
    double sum = 0;
    double value;

    while (fscanf(f, "%lf", &value) == 1) 
    {
        sum += value; 
        count++; 
    }

    fclose(f); 

    if (count > 0) 
    {
        *avg = sum / count;
        return 0;
    }

    return -1;
}

int dispersion(const char *path, double avg, double *std) 
{
    FILE *f = fopen(path, "r"); 

    if (!f)
        return -1; 
    int count = 0;
    *std = 0;
    double value;

    while (fscanf(f, "%lf", &value) == 1) 
    {
        *std += (value - avg) * (value - avg);
        count++; 
    }

    fclose(f); 

    if (count > 0) 
    {
        *std /= count;
        return 0;
    }

    return -1;
}

int check(const char *path, double avg, double std) 
{
    FILE *f = fopen(path, "r"); 

    if (!f)
        return -1; 

    double sigma = sqrt(std);
    double count = 0;
    int total_count = 0;
    double value;

    while (fscanf(f, "%lf", &value) == 1) 
    {
        if (value > avg - 3 * sigma && value < avg + 3 * sigma)
            count++;
        total_count++;
    }

    fclose(f); 
    return count / total_count >= 0.9973;
}