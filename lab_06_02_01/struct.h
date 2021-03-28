#ifndef STRUCT_H
#define STRUCT_H
#define MAX_NAME 25
#define MAX_STRUCT 15

typedef struct
{
	char name[MAX_NAME + 1];
	float mass; 
	float volume; 
} product_t;

#endif 