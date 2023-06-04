#include "sort.h"
#include <stdlib.h>
#include <string.h>

void insertion_sort(void *arr,
                    int arr_length,
                    int e_size,
                    int (*compare)(const void*, const void*)) {
    // Add check for size 0 | 1
    int arr_size = e_size * arr_length;
    char *key = malloc(e_size);
    int i, j;
    for (i = e_size; i < arr_size; i += e_size) {
        memcpy(key, (char *)arr + i, e_size);
        j = i - e_size;
        while (j > 0 && (*compare)((char *)arr + j, key)) {
            memcpy((char *)arr + (j + e_size), (char *)arr + j, e_size);
            j -= e_size;
        }
        memcpy((char *)arr + (j + e_size), key, e_size);
    }
    free(key);
}
