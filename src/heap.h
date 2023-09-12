#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

#define parent(i) (i >> 1)
#define left(i) (i << 1)
#define right(i) ((i << 1) + 1)

typedef struct {
    size_t heap_size;
    void *arr; // arr is 0-indexed, but parent, left, right return 1-based indexes
    size_t e_size;
    size_t arr_length;
    int (*cmp)(const void*, const void*); // Use > for max-heap and < for min-heap
} heap;

void build_heap(heap h, size_t n);
void heapify(heap h, size_t i);
void print_heap(heap h);

#endif