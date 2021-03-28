#ifndef SPLITTTING_H_INCLUDED
#define SPLITTTING_H_INCLUDED

#define SMAX 256
#define WMAX 16

int split_and_sort(char text[]);
int is_delimeter(char c);
int contains(char (*a)[WMAX], int n, char text[]);

#endif // SPLITTTING_H_INCLUDED
