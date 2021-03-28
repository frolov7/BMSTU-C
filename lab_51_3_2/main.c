#include <stdio.h>
#include "function.h"

int main(int argc, char **argv) 
{
    if (argc != 2) 
        return -1; 

    double avg;
    double std;

    if (average(argv[1], &avg))
        return -1;

    if (dispersion(argv[1], avg, &std))
        return -1;

    int result = check(argv[1], avg, std);

    if (result == -1)
        return -1;

    printf("%d", result);
    return 0;
}