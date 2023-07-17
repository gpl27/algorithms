#ifndef HEAP_H
#define HEAP_H

#define parent(i) (i >> 1)
#define left(i) (i << 1)
#define right(i) ((i << 1) + 1)

typedef struct {
    int heap_size;
    int e_size;
    void *arr;
    int arr_length;
    // Add compare function
} heap;

void build_max_heap(heap h, int n);
void max_heapify(heap h, int i);
void *max_heap_insert(heap h);
void *max_heap_extract_max(heap h);
void print_heap(heap h);



#endif