#include "helpers.h"

#include <stdlib.h>
#include <string.h>

void swap(void* a, void* b, int e_size) {
    char *tmp = malloc(e_size);
    memcpy(tmp, a, e_size);
    memcpy(a, b, e_size);
    memcpy(b, tmp, e_size);
    free(tmp);
}