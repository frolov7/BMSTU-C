#include "transform.h"

void stay_first(char *word) 
{
    int j = 0; 

    for (int i = 0; word[i]; i++)
        if (strchr(word, word[i]) == word + i) 
            word[j++] = word[i]; 
    
    word[j] = '\0'; 
}

int make_result(char *result, char words[SMAX][WMAX + 1], int n) 
{
    int was_added = 0; 

    for (int i = n - 2; i >= 0; i--) 
    { 
        if (!strcmp(words[i], words[n - 1]))
            continue; 
        
        stay_first(words[i]); 

        if (was_added) 
        {
            strcat(result, " "); 
        }
        else 
        {
            was_added = 1; 
        }

        strcat(result, words[i]); 
    }

    return was_added;
}

int solve(char *text) 
{
    char words[SMAX][WMAX + 1]; 
    int n = 0; 

    for (char *word = strtok(text, DELIMETERS); word; word = strtok(NULL, DELIMETERS)) 
    {
        if (strlen(word) > WMAX) 
            return EXIT_FAILURE;

        strcpy(words[n++], word); 
    }

    if (n < 2)
        return EXIT_FAILURE; 

    text[0] = '\0';

    if (!make_result(text, words, n))
        return EXIT_FAILURE;

    printf("Result: %s\n", text);
    return EXIT_SUCCESS;
}
