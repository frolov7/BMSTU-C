#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"

//вариант №2
int main() 
{
    dlist_t list = init_list();

    while (1) 
    {
        printf("Select action:\n");
        printf("1. Print students\n");
        printf("2. Add student\n");
        printf("3. Sort students\n");
        printf("4. Quit\n");
        int item = read_integer(">");

        if (item == 4)
            break;

        if (item == 1) 
        {
            print_forward(list, print_student);
        }
        else if (item == 2) 
        {
            if (add_back(&list, read_student())) 
            {
                printf("Memory error\n");
                break;
            }
        }
        else 
        {
            insertion_sort(&list, compare);
        }
    }

    free_list(&list, free_student);

    return 0;
}