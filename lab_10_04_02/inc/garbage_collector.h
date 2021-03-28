#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

#include <stdlib.h>

typedef struct garbage_collector_t
{
    void **pointers;
    size_t size;
} garbage_collector_t;

garbage_collector_t init_gc();
void *malloc_gc(garbage_collector_t *gc, size_t size);
void free_gc(garbage_collector_t *gc);

#endif