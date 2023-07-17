/*!
 * Consider changing int to type defined in stdlib
 */
#include "sort.h"
#include "helpers.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
        while (j >= 0 && (*compare)((char *)arr + j, key)) {
            memcpy((char *)arr + (j + e_size), (char *)arr + j, e_size);
            j -= e_size;
        }
        memcpy((char *)arr + (j + e_size), key, e_size);
    }
    free(key);
}

void shell_sort_insert(void *arr,
                       int arr_length,
                       int e_size,
                       int (*compare)(const void*, const void*),
                       int s,
                       int h) {

    int arr_size = e_size * arr_length;
    char *key = malloc(e_size);
    int i, j;
    for (j = e_size*(s + h); j < arr_size; j += e_size * h) {
        memcpy(key, (char *)arr + j, e_size);
        i = j - (e_size * h);
        while(i >= 0 && (*compare)((char *)arr + i, key)) {
            memcpy((char *)arr + i + (e_size * h), (char *)arr + i, e_size);
            i -= (e_size * h);
        }
        memcpy((char *)arr + i + (e_size * h), key, e_size);
    }
    free(key);
}

void shell_sort(void *arr,
                int arr_length,
                int e_size,
                int (*compare)(const void*, const void*)) {

    int steps = (int) log2((double) arr_length);
    int p, h, j;
    for (p = steps; p > 0; p--) {
        h = pow(2.0, (double)(p - 1));
        for (j = 0; j < h; j++) {
            shell_sort_insert(arr, arr_length, e_size, compare, j, h);
        }
    }
}

void bubble_sort(void *arr,
               int arr_length,
               int e_size,
               int (*compare)(const void*, const void*)) {
    // Add check for size 0 | 1
    int arr_size = e_size * arr_length;
    int swapped = 1;
    int i;
    while (swapped) {
        swapped = 0;
        for (i = 0; i < (arr_size - e_size); i += e_size) {
            if ((*compare)((char *)arr + i, (char *)arr + (i + e_size))) {
                swap((char *)arr + i, (char *)arr + (i + e_size), e_size);
                swapped = 1;
            }
        }
    }
}

void comb_sort(void *arr,
               int arr_length,
               int e_size,
               int (*compare)(const void*, const void*)) {

    int arr_size = e_size * arr_length;
    int gap = (int) (arr_length/1.3);
    int swapped = 1;
    int i;
    while (swapped) {
        gap = (gap > 1) ? (int) (gap/1.3) : 1;
        swapped = (gap == 1) ? 0 : 1;
        for (i = e_size*gap; i < arr_size; i += e_size) {
            if ((*compare)((char *)arr + i - (e_size*gap), (char *)arr + i)) {
                swap((char *)arr + i - (e_size*gap), (char *)arr + i, e_size);
                swapped = 1;
            }
        }
    }
}
