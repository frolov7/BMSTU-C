#include "student.h"

char* read_string(const char *message) 
{
    printf("%s", message); 
    int size = 0; 
    int capacity = 1; 
    char *s = (char *) malloc(sizeof(char)); 

    if (s == NULL)
        return NULL;

    for (char c = getchar(); c != '\n'; c = getchar()) 
    {
        s[size++] = c;

        if (size >= capacity) 
        { 
            capacity *= 2; 
            s = (char *) realloc(s, capacity * sizeof(char)); 
        }
    }

    s[size] = '\0'; 

    return s; 
}

int is_integer(char *s) 
{
    for (int i = 0; s[i]; i++)
        if (s[i] < '0' || s[i] > '9')
            return 0;

    return 1;
}

int read_integer(const char *message) 
{
    char *s = read_string(message); 

    while (!is_integer(s) || atoi(s) < 1) 
    {
        free(s); 
        s = read_string("Invalid value, try again: ");
    }

    int value = atoi(s); 
    free(s);
    return value; 
}

void free_int(void *value) 
{
    free((int*)value);
}

student_t* read_student() 
{
    student_t *student = (student_t *) malloc(sizeof(student_t));
    student->name = read_string("Enter name: ");
    student->age = read_integer("Enter age: ");
    student->marks = init_list();

    int count = read_integer("Enter number of marks: ");
    int is_correct = 1;

    for (int i = 0; i < count && is_correct; i++) 
    {
        int *mark = (int *) malloc(sizeof(int));
        *mark = read_integer("Enter mark: ");
        is_correct = !add_back(&student->marks, mark);
    }

    if (!is_correct) 
    {
        free_list(&student->marks, free_int);
        free(student->name);
        free(student);
        return NULL;
    }

    return student;
}

int compare(void *student1, void *student2) 
{
    student_t *s1 = (student_t *) student1;
    student_t *s2 = (student_t *) student2;

    return strcmp(s1->name, s2->name);
}

void print_mark(void *mark) {
    printf("%d ", *((int *) mark));
}

void print_student(void *student) 
{
    printf("%s, age: %d, marks: ", ((student_t *)student)->name, ((student_t *)student)->age);
    print_forward(((student_t *)student)->marks, print_mark);
    printf("\n");
}

void free_student(void *student) 
{
    free(((student_t *)student)->name);
    free_list(&((student_t *)student)->marks, free_int);
}