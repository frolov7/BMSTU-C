#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splittting.h"
#define N 256

int check_line(char *line)
{
    char get;
    int i = 0;
    while ((get = getchar()) != '\n' && get != EOF)
    {
        if (i < N - 1)
            line[i++] = get;
        if (i >= N - 1)
            return 1;
    }
    line[i] = '\0';
    if (i == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char text[SMAX];
    //fgets(text, SMAX, stdin);
    if (check_line(text) == 0)
    {
        //text[strlen(text) - 1] = '\0';
        if (split_and_sort(text) == 0)
        {
            return 0;
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        return EXIT_FAILURE;
    }
}
