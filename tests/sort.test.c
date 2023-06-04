#include "../src/sort.h"
#include "./test.h"
#include <assert.h>
#include <string.h>

int compare_int(const void *a, const void *b) {
    return *(int *)a > *(int *)b;
}
void test_insertion_sort(void) {
    // Add array generation
    int arr[] = {5, 4, 3, 2, 1, 0};
    int arr_sorted[] = {0, 1, 2, 3, 4, 5};
    insertion_sort(arr, 6, sizeof(int), compare_int);
    assert(memcmp(arr, arr_sorted, 6*sizeof(int)));
}

void test_sort(void) {

    // Run tests
    test_insertion_sort();

}

