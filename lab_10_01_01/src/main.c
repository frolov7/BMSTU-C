#include "../inc/list.h"
#include "../inc/funcs.h"

// ввод строки
char *read_string(FILE *f) 
{
    int size = 0; 
    int capacity = 1; 
    char *s = (char *) malloc(sizeof(char)); 

    if (s)
    {
        for (char c = fgetc(f); c != '\n' && c != EOF; c = fgetc(f)) 
        {
            s[size++] = c; 

            if (size >= capacity) 
            { 
                capacity *= 2; 
                s = (char *) realloc(s, capacity * sizeof(char));
            }
        }

        s[size] = '\0'; 
    }
    return s; 
}

// ввод списка из файла
node_t *read_list(FILE *f) 
{
    node_t *list = NULL;

    while (!feof(f)) 
    {
        char *s = read_string(f); 

        if (s && !push_front(&list, s))
            continue;

        while (list) 
        {
            char *s = (char *)pop_front(&list);
            free(s);
        }
        break;
    }

    return list; 
}

// вывод элемента списка
void print(FILE *f, void *value) 
{
    fprintf(f, "%s\n", ((char *)value));
}

void free_str(void *data) 
{
    free((char*) data);
}

int comparator(const void *a, const void *b) 
{
    char *pa = (char *)a;
    char *pb = (char *)b;

    return strcmp(pa, pb);
}

int main(int argc, char **argv) 
{
    int error = 0;
    FILE *fin = !strcmp(argv[1], "stdin") ? stdin : fopen(argv[1], "r"); 

    if (!fin) 
    {
        error = -1;
    }
    else
    {
        node_t *list = read_list(fin); 
        fclose(fin); 

        FILE *fout = !strcmp(argv[2], "stdout") ? stdout : fopen(argv[2], "w");

        if (!strcmp(argv[3], "sort")) 
        {
            list = sort(list, comparator);
            print_list(fout, list, print);
        }
        else if (!strcmp(argv[3], "reverse")) 
        {
            list = reverse(list);
            print_list(fout, list, print);
        }
        else if (!strcmp(argv[3], "pop_front")) 
        {
            while (list) 
            {
                char *s = pop_front(&list);
                fprintf(fout, "%s\n", s);
                free(s);
            }
        }
        else if (!strcmp(argv[3], "pop_back")) 
        {
            while (list) 
            {
                char *s = pop_back(&list);
                fprintf(fout, "%s\n", s);
                free(s);
            }
        }

        fclose(fout);

        iterate_list(list, free_str);
        free_list(&list);
    }
    return error;
}