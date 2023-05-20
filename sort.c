#include <stdlib.h>

void *insertion_sort(void *arr,
                    int arr_size,
                    int e_size,
                    int (*compare)(const void*, const void*)) {
    // Add check for size 0 | 1

    void *key;
    int i, j;
    for (i = e_size; i < arr_size; i += e_size) {
        key = &(arr + i);
        j = i - e_size;
        while (j > 0 && compare(&(arr + j), key)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = *key;
    }
}


int compare_int(const int a, const int b) {
    return a >= b;
}

int main(void) {
    int my_arr = {5, 4, 3, 2, 1};
    print_arr(my_arr);
    my_arr = insertion_sort(my_arr);
    print_arr(my_arr);
    return 0;
}
