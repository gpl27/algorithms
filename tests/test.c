/*!
 * Auxiliary functions for testing
 * TODO:
 *      custom assert functions
 *      random array
 *      ascending array
 *      descending array
 */
int gre_int(const void *a, const void *b) {
    return *(int *)a > *(int *)b;
}

int les_int(const void *a, const void *b) {
    return *(int *)a < *(int *)b;
}
