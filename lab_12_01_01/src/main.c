#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/functions.h"
#include "../inc/work_arr.h"



int main(int argc, char **argv) 
{
    int exit_code = 0;

    if (argc != 3 && argc != 4) 
        exit_code = -1;
    else if (argc == 4 && strcmp(argv[3], "f"))
        exit_code = -1;
    else
    {
        FILE *fin = fopen(argv[1], "r"); 

        if (!fin)
            exit_code = -1;
        else
        {
            int n = count_elements(fin);
            fclose(fin);
        
            if (n == -1)
                exit_code = -1;
            else
            {
                fin = fopen(argv[1], "r");
                int *array = read_array(fin, n);
                fclose(fin);

                if (!array)
                    exit_code = -1;
                else
                {
                    int *filtered_begin = array;
                    int *filtered_end = array + n;

                    if (argc == 4) 
                    {
                        filtered_begin = NULL;
                        filtered_end = NULL;

                        int result = key(array, array + n, &filtered_begin, &filtered_end);
                        if (result == -1)
                            exit_code = -1;
                        else
                        {
                            filtered_begin = malloc(result * sizeof(int));
                            key(array, array + n, &filtered_begin, &filtered_end);
                        }

                        free(array);
                    }
                    
                    if (!exit_code)
                    {
                        mysort(filtered_begin, filtered_end - filtered_begin, sizeof(int), compare_int);

                        exit_code = print_file(filtered_begin, filtered_end, argv[2]);
                        free(filtered_begin);
                    }
                }
            }
        }
    }

    return exit_code;
}