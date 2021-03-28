#ifndef MY_STRING_H
#define MY_STRING_H

#define SIZEBUF 255
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include"../inc/my_string.h"

int nunumlenm(unsigned long int x);
void conver(char *newnum, unsigned long long int num);
void change(char *newnum, int len);
int copy(char *str, size_t len, size_t size, long x);
//int intstr(char *str, size_t len, size_t size, long x);
int tostring(char *newnum, unsigned long long int num);
int my_snprintf(char *str, size_t size, const char *format, ...);

#endif