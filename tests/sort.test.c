#include "../src/sort.h"
#include "./test.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_insertion_sort(void) {
    // Add array generation
    int arr[] = {5, 4, 3, 2, 1, 0};
    int arr_sorted[] = {0, 1, 2, 3, 4, 5};
    insertion_sort(arr, 6, sizeof(int), gre_int);
    assert(memcmp(arr, arr_sorted, 6*sizeof(int)) == 0);
    printf("    Insertion Sort - OK!\n");
}

void test_shell_sort(void) {
    // Add array generation
    int arr[] = {5, 4, 3, 2, 1, 0};
    int arr_sorted[] = {0, 1, 2, 3, 4, 5};
    shell_sort(arr, 6, sizeof(int), gre_int);
    assert(memcmp(arr, arr_sorted, 6*sizeof(int)) == 0);
    printf("    Shell Sort - OK!\n");
}

void test_bubble_sort(void) {
    // Add array generation
    int arr[] = {5, 4, 3, 2, 1, 0};
    int arr_sorted[] = {0, 1, 2, 3, 4, 5};
    bubble_sort(arr, 6, sizeof(int), gre_int);
    assert(memcmp(arr, arr_sorted, 6*sizeof(int)) == 0);
    printf("    Bubble Sort - OK!\n");
}

void test_comb_sort(void) {
    // Add array generation
    int arr[] = {5, 4, 3, 2, 1, 0};
    int arr_sorted[] = {0, 1, 2, 3, 4, 5};
    comb_sort(arr, 6, sizeof(int), gre_int);
    assert(memcmp(arr, arr_sorted, 6*sizeof(int)) == 0);
    printf("    Comb Sort - OK!\n");
}

void test_heap_sort(void) {
    // Add array generation
    int arr[] = {5, 4, 3, 2, 1, 0};
    int arr_sorted[] = {0, 1, 2, 3, 4, 5};
    heap_sort(arr, 6, sizeof(int), gre_int);
    assert(memcmp(arr, arr_sorted, 6*sizeof(int)) == 0);
    printf("    Heap Sort - OK!\n");
}

void test_sort(void) {

    // Run tests
    test_insertion_sort();
    test_shell_sort();
    test_bubble_sort();
    test_comb_sort();
    test_heap_sort();
    printf("> Test passed.\n");

}
