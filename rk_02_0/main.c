#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct town_t 
{
    char name[100];
    int year; 
    int population; 
} town_t;

town_t read_town(FILE *f) 
{
    town_t town;
    fgets(town.name, 100, f);
    fscanf(f, "%d%*[^\n]", &town.year);
    fscanf(f, "%d%*[^\n]", &town.population);

    town.name[strlen(town.name) - 1] = '\0';
    return town; 
}

void print_result(FILE *f, double average_population, int population) 
{
    fprintf(f, "%d", (int) (population - average_population));
}

int process(FILE *fin, FILE *fout) 
{
    fseek(fin, 0, SEEK_END);
    long size = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    if (size == 0)
        return -1;

    town_t best_town;
    best_town.name[0] = '\0'; 

    double population = 0; 
    int count = 0; 

    while (!feof(fin)) 
    {
        town_t town = read_town(fin);

        int len = strlen(town.name); 

        if (len > strlen(best_town.name))
            best_town = town;

        population += town.population; 
        count++; 
    }

    if (count == 0)
        return -1;

    double average_population = population * 1.0 / count; 
    print_result(fout, average_population, best_town.population);
    return 0;
}

int main() 
{
    FILE *fin = fopen("in.txt", "r"); 

    if (!fin)
        return -1;

    FILE *fout = fopen("out.txt", "w");

    int result = process(fin, fout);

    fclose(fin);
    fclose(fout);
    return result;
}