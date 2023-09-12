/*!
 * TODO:
 *  heap.h tests
 *  use ERRNO to avoid crashing tests
 */
#include "./sort.test.h"
#include "./heap.test.h"
#include <stdio.h>

int main(void) {
    
    printf("> Running test suite for heap.h ...\n");
    test_heap();

    printf("> Running test suite for sort.h ...\n");
    test_sort();

    return 0;
}
