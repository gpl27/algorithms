/*!
 * TODO:
 *  Heap Sort
 *  QSort
 *  Linear time sorting
 */
#include "sort.h"
#include "helpers.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

void insertion_sort(void *arr,
                    size_t arr_length,
                    size_t e_size,
                    int (*cmp)(const void*, const void*)) {
    if (arr_length <= 1)
        return;
    char *carr = (char *) arr;
    char *key = malloc(e_size);
    size_t i, j;
    for (i = 1; i < arr_length; i++) {
        memcpy(key, carr + (i*e_size), e_size);
        j = i;
        while (j > 0 && cmp(carr + ((j-1)*e_size), key)) {
            memcpy(carr + (j*e_size), carr + ((j-1)*e_size), e_size);
            j--;
        }
        memcpy(carr + (j*e_size), key, e_size);
    }
    free(key);
}

void shell_sort_insert(void *arr,
                       size_t arr_length,
                       size_t e_size,
                       int (*cmp)(const void*, const void*),
                       int s,
                       int h) {
    char *carr = (char *) arr;
    char *key = malloc(e_size);
    size_t i, j;
    for (j = (s + h); j < arr_length; j += h) {
        memcpy(key, carr + (j*e_size), e_size);
        i = j;
        while(i >= h && cmp(carr + ((i-h)*e_size), key)) {
            memcpy(carr + (i*e_size), carr + ((i-h)*e_size), e_size);
            i -= h;
        }
        memcpy(carr + (i*e_size), key, e_size);
    }
    free(key);
}

void shell_sort(void *arr,
                size_t arr_length,
                size_t e_size,
                int (*cmp)(const void*, const void*)) {

    int steps = (int) log2((double) arr_length);
    int p, h, j;
    for (p = steps; p > 0; p--) {
        h = pow(2.0, (double)(p - 1));
        for (j = 0; j < h; j++) {
            shell_sort_insert(arr, arr_length, e_size, cmp, j, h);
        }
    }
}

void bubble_sort(void *arr,
               size_t arr_length,
               size_t e_size,
               int (*cmp)(const void*, const void*)) {
    char *carr = (char *) arr;
    // Add check for size 0 | 1
    size_t arr_size = e_size * arr_length;
    int swapped = 1;
    size_t i;
    while (swapped) {
        swapped = 0;
        for (i = 0; i < (arr_size - e_size); i += e_size) {
            if (cmp(carr + i, carr + (i + e_size))) {
                swap(carr + i, carr + (i + e_size), e_size);
                swapped = 1;
            }
        }
    }
}

void comb_sort(void *arr,
               size_t arr_length,
               size_t e_size,
               int (*cmp)(const void*, const void*)) {
    char *carr = (char *) arr;
    size_t arr_size = e_size * arr_length;
    int gap = (int) (arr_length/1.3);
    int swapped = 1;
    size_t i;
    while (swapped) {
        gap = (gap > 1) ? (int) (gap/1.3) : 1;
        swapped = (gap == 1) ? 0 : 1;
        for (i = e_size*gap; i < arr_size; i += e_size) {
            if (cmp(carr + i - (e_size*gap), carr + i)) {
                swap(carr + i - (e_size*gap), carr + i, e_size);
                swapped = 1;
            }
        }
    }
}
