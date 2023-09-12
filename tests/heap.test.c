#include "../src/heap.h"
#include "./test.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_max_heap(void) {
    int arr[] = {0, 1, 2, 3, 4, 5};
    int max_heap[] = {5, 4, 2, 3, 1, 0};
    heap h;
    h.cmp = gre_int;
    h.e_size = sizeof(int);
    h.arr_length = 6;
    h.arr = arr;
    h.heap_size = h.arr_length;
    build_heap(h, h.heap_size);
    assert(memcmp(arr, max_heap, 6*sizeof(int)) == 0);
    printf("    Max Heap - OK!\n");
}

void test_min_heap(void) {
    int arr[] = {5, 4, 3, 2, 1, 0};
    int min_heap[] = {0, 1, 3, 2, 4, 5};
    heap h;
    h.cmp = les_int;
    h.e_size = sizeof(int);
    h.arr_length = 6;
    h.arr = arr;
    h.heap_size = h.arr_length;
    build_heap(h, h.heap_size);
    assert(memcmp(arr, min_heap, 6*sizeof(int)) == 0);
    printf("    Min Heap - OK!\n");

}

void test_heap(void) {
    test_max_heap();
    test_min_heap();
    printf("> Test passed.\n");
}
