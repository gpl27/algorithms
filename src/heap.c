/*!
 * TODO:
 * priority queue
 *   heap_insert
 *   extract
 *   top
 *   increase_key
 */
#include "heap.h"
#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Prints an integer heap
void print_heap(heap h) {
    char *arr = (char *)h.arr;
    int indent = (int) log2(h.heap_size)+1;
    int curr = 0;
    for (int i = 1; i <= h.heap_size; i = i*2) {
        for (int k = 1; k < pow(2, indent-1); k++)
            printf("    ");
        for (int j = 0; (j < i) && (curr < h.heap_size); j++) {
            printf("%d", *(arr + h.e_size * curr++));
            for (int k = 0; k < pow(2, indent); k++)
                printf("    ");
        }
        indent--;
        printf("\n");
    }
}

// Usar funcao de compare
void heapify(heap h, size_t i) {
    char *arr = (char *)h.arr;
    size_t largest;
    size_t l = left(i);
    size_t r = right(i);

    if (l <= h.heap_size && 
            h.cmp(arr + (l-1)*h.e_size, arr + (i-1)*h.e_size)) {
        largest = l;
    } else {
        largest = i;
    }

    if (r <= h.heap_size && 
            h.cmp(arr + (r-1)*h.e_size, arr + (largest-1)*h.e_size)) {
        largest = r;
    } 

    if (largest != i) {
        swap(arr + (i-1)*h.e_size, arr + (largest-1)*h.e_size, h.e_size);
        heapify(h, largest);
    }

}

void build_heap(heap h, size_t n) {
    h.heap_size = n;
    for (int i = n >> 1; i > 0; i--) {
        heapify(h, i);
    }
}
