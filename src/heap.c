/*!
 * TODO:
 *  Type generic heap
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
void max_heapify(heap h, int i){
    char *arr = (char *)h.arr;
    int largest;
    int l = left(i);
    int r = right(i);

    if (l <= h.heap_size && 
       *(arr + (l - 1) * h.e_size) > *(arr + (i - 1) * h.e_size)) {
        largest = l;
    } else {
        largest = i;
    }

    if (r <= h.heap_size && 
       *(arr + (r - 1) * h.e_size) > *(arr + (largest - 1) * h.e_size)) {
        largest = r;
    } 

    if (largest != i) {
        swap(arr + (i - 1) * h.e_size, arr + (largest - 1) * h.e_size, h.e_size);
        max_heapify(h, largest);
    }

}

void build_max_heap(heap h, int n) {
    h.heap_size = n;
    for (int i = n >> 1; i > 0; i--) {
        max_heapify(h, i);
    }
}