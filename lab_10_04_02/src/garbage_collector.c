#include "../inc/garbage_collector.h"

garbage_collector_t init_gc()
{
    garbage_collector_t gc;
    gc.size = 0;
    gc.pointers = (void **) malloc(sizeof(void *));

    return gc;
}

void *malloc_gc(garbage_collector_t *gc, size_t size)
{
    void *pointer = calloc(size, sizeof(char));
    gc->pointers[gc->size++] = pointer;
    gc->pointers = realloc(gc->pointers, (gc->size + 1) * sizeof(void *));
    return pointer;
}

void free_gc(garbage_collector_t *gc)
{
    for (size_t i = 0; i < gc->size; i++)
        free(gc->pointers[i]);

    free(gc->pointers);
}