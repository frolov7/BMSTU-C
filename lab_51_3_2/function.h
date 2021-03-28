#include <stdio.h>
#ifndef MY_FILE
#include <math.h>
#include <stdlib.h>
#define MY_FILE

int average(const char *path, double *avg); 
int dispersion(const char *path, double avg, double *std); 
int check(const char *path, double avg, double std); 

#endif 