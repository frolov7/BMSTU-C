#include "functions.h"

student_t *read_students(const char *path, int *n) 
{
    FILE *f = fopen(path, "rb");
    
    if (!f)
        return NULL; 
        
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (size == 0 || size % sizeof(student_t) != 0)
        return NULL;

    *n = size / sizeof(student_t);
    student_t *students = (student_t *) malloc(size);

    for (int i = 0; i < *n; i++)
        fread(students + i, sizeof(student_t), 1, f);

    fclose(f);
    return students;
}

void save_students(const char *path, student_t *students, int n) 
{
    FILE *f = fopen(path, "wb");

    for (int i = 0; i < n; i++)
        fwrite(students + i, sizeof(student_t), 1, f);
    
    fclose(f);
}

int compare(student_t student1, student_t student2) 
{
    int surnames = strcmp(student1.surname, student2.surname);

    if (surnames)
        return surnames < 0;

    return strcmp(student1.name, student2.name) < 0;
}

int sort_students(const char *path1, const char *path2) 
{
    int n;
    student_t *students = read_students(path1, &n);

    if (students == NULL)
        return -1;

    for (int k = n / 2; k > 0; k /= 2) 
    {
        for (int i = k; i < n; i++) 
        {
            student_t tmp = students[i]; 
            int j = i;

            while (j >= k && compare(tmp, students[j - k])) 
            {
                students[j] = students[j - k];
                j -= k;
            }

            students[j] = tmp;
        }
    }

    save_students(path2, students, n);
    free(students);

    return 0;
}

int print_students(const char *path1, const char *path2, const char *substr) 
{
    FILE *f = fopen(path1, "rb");

    if (!f)
        return -1;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (size == 0 || size % sizeof(student_t) != 0)
        return -1;

    student_t student; 
    int len = strlen(substr);
    int result = -1;
    
    FILE *fout = fopen(path2, "wb");

    while (fread(&student, sizeof(student_t), 1, f)) 
    {
        int student_len = strlen(student.surname);

        if (student_len < len)
            continue;

        if (strncmp(student.surname, substr, len))
            continue;

        fwrite((const char *) &student, sizeof(student), 1, fout);
        result = 0;
    }

    fclose(f);
    fclose(fout);
    return result;
}

double average_mark(student_t student) 
{
    double avg = 0;

    for (int i = 0; i < 4; i++)
        avg += student.marks[i];

    return avg / 4;
}

double average_score(student_t *students, int n) 
{
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += average_mark(students[i]);

    return sum / n;
}

int remove_students(const char *path) 
{
    int n;
    student_t *students = read_students(path, &n);

    if (students == NULL)
        return -1;

    double avg = average_score(students, n);
    int j = 0;

    for (int i = 0; i < n; i++)
        if (average_mark(students[i]) >= avg)
            students[j++] = students[i];
    
    if (j > 0)
        save_students(path, students, j);
    
    free(students);

    return j > 0 ? 0 : -1;
}
