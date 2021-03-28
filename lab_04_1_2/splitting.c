#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "splittting.h"

int is_delimeter(char c)
{
    if (c == ' ' || c == ',' || c == ';' || c == ':' || c == '-' || c == '.' || c == '!' || c == '?')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int contains(char (*a)[WMAX], int n, char text[])
{
    int in = -1;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i], text) == 0)
        {
            in = 0;
            break;
        }
    }
    return in;
}

int split_and_sort(char text[])
{
    char w[WMAX];
    w[0] = '\0';
    char words[128][WMAX]; 
    int i = 0, n = 0, wl = 0;
    while (text[i] != '\0')
    {
        if (is_delimeter(text[i]) == 0) 
        {
            w[wl] = '\0'; 
            if (wl > 0)
            {
                if (contains(words, n, w) == -1) 
                {
                    strcpy(words[n], w);
                    n++;
                }
                w[0] = '\0';
                wl = 0;
            }
            while (text[i + 1] != '\0' && is_delimeter(text[i + 1]) == 0)
            {
                i++;
            }
        }
        else
        {
            w[wl] = text[i];
            wl++;
            if (wl > WMAX) 
            {
                return -1;
            }
        }
        i++;
    }
    if (wl > 0)
    {
        if (wl > WMAX) 
        {
            return -1;
        }
        else
        {
            w[wl] = '\0';
            if (contains(words, n, w) == -1) 
            {
                strcpy(words[n], w);
                n++;
            }
        }
    }
    if (n <= 1) 
    {
        return -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(words[j], words[j + 1]) == 1)
            {
                char t[WMAX];
                strcpy(t, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], t);
            }
        }
    }
    printf("Result: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}
