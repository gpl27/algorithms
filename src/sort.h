#ifndef SORT_H
#define SORT_H

void insertion_sort(void *arr,
                    int arr_length,
                    int e_size,
                    int (*compare)(const void*, const void*));

#endif
