#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct field_t 
{
    int n;
    int m;
    int *cells;
} field_t;

// инициализация поля
field_t init_field(int n, int m) 
{
    field_t field;
    field.n = n;
    field.m = m;
    field.cells = (int *) malloc(n * m * sizeof(int));

    return field;
}

// освобождение памяти из-по поля
void free_field(field_t *field) 
{
    free(field->cells);
    field->cells = NULL;
}

// чтение состояния поля
int read_field(char *path, field_t *field) 
{
    FILE *f = fopen(path, "r");

    if (!f) 
    {
        printf("Unable to open file '%s'\n", path);
        return 0;
    }
    fscanf(f, "%d %d", &field->n, &field->m);
    free_field(field);
    *field = init_field(field->n, field->m);
    int *cells = field->cells;
    char c;

    for (int i = 0; i < field->n; i++) 
    {
        for (int j = 0; j < field->m; j++) 
        {
            fscanf(f, "%c", &c);
            *cells++ = c == '#' || c == '1';
        }

        fscanf(f, "%*c");
    }

    fclose(f);
    return 1;
}

// вывод поля
void print_field(field_t field) 
{
    for (int i = 0; i < field.n; i++) 
    {
        for (int j = 0; j < field.m; j++)
            printf("%c", *field.cells++ ? '#' : ' ');
        printf("\n");
    }
}

int step_life(field_t *field, field_t *field2) 
{
    int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    for (int i = 0; i < field->n; i++) 
    {
        for (int j = 0; j < field->m; j++) 
        {
            int neighbours = 0; // количество соседей

            for (int k = 0; k < 8; k++) 
            {
                int y = (i + dy[k] + field->n) % field->n;
                int x = (j + dx[k] + field->m) % field->m;
                neighbours += *(field->cells + y * field->m + x) ? 1 : 0;
            }

            int state = *(field->cells + i * field->m + j);

            if (!state && neighbours == 3) 
            { 
                *(field2->cells + i * field->m + j) = 1;
            }
            else if (state && (neighbours < 2 || neighbours > 3)) 
            { 
                *(field2->cells + i * field->m + j) = 0;   
            }
            else 
            {
                *(field2->cells + i * field->m + j) = state;
            }
        }
    }

    int was_changed = 0;
    int live_cells = 0;

    for (int i = 0; i < field->n * field->m; i++) 
    {
        if (*(field->cells + i) != *(field2->cells + i))
            was_changed = 1;

        *(field->cells + i) = *(field2->cells + i);

        if (*(field->cells + i))
            live_cells++;
    }

    return was_changed && live_cells;
}

int main(void) 
{
    printf("Type command for action:\n");
    printf("Commands:\n");
    printf("  [l]oad path - load field from file in path\n");
    printf("  [n]ext - print next state\n");
    printf("  [s]tep N - make N steps and print state\n");
    printf("  [q]uit - quit from app\n");

    field_t field;
    field.cells = NULL;
    field_t field2;
    field2.cells = NULL;

    char command[100];
    char path[100];
    int n;
    int have_field = 0;

    while (1) {
        printf(">");
        scanf("%s", command);

        if (!strcmp(command, "l") || !strcmp(command, "load")) 
        {
            scanf("%s", path);
            have_field = 0;

            if (read_field(path, &field)) 
            {
                field2 = init_field(field.n, field.m);
                print_field(field);
                have_field = 1;
            }
        }
        else if (!strcmp(command, "q") || !strcmp(command, "quit")) 
        {
            break;
        }
        else if (!strcmp(command, "n") || !strcmp(command, "next")) 
        {
            if (!have_field) 
            {
                printf("Field was not loaded yet!\n");
                continue;
            }

            int can_continue = step_life(&field, &field2);
            print_field(field); 

            if (!can_continue) 
            {
                printf("Game over\n");
                break;
            }
        }
        else if (!strcmp(command, "s") || !strcmp(command, "step")) 
        {
            if (!have_field) 
            {
                printf("Field was not loaded yet!\n");
                continue;
            }

            scanf("%d", &n);

            while (n && step_life(&field, &field2))
                ;

            print_field(field);

            if (n) 
            {
                printf("Game over\n");
                break;
            }
        }
    }

    free_field(&field);
    free_field(&field2);

    return 0;
}