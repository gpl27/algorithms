#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void insertion_sort(void *arr,
                    size_t arr_length,
                    size_t e_size,
                    int (*cmp)(const void*, const void*));

void shell_sort(void *arr,
                size_t arr_length,
                size_t e_size,
                int (*cmp)(const void*, const void*));

void bubble_sort(void *arr,
                 size_t arr_length,
                 size_t e_size,
                 int (*cmp)(const void*, const void*));

void comb_sort(void *arr,
               size_t arr_length,
               size_t e_size,
               int (*cmp)(const void*, const void*));
#endif
