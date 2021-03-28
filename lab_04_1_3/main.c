#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transform.h"

int main() 
{
    char s[SMAX+ 2];
    
    if (!fgets(s, SMAX+ 2, stdin))
        return EXIT_FAILURE;
    
    int length = strlen(s); 

    if (length < 2 || length > SMAX)
        return EXIT_FAILURE;

    s[length - 1] = '\0'; 
    
    return solve(s);
}