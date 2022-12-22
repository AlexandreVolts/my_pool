#include <stdlib.h>

static void merge(int *array, size_t n1, size_t n2)
{
    int cpy[n1 + n2];
    size_t i = 0;
    size_t j = 0;

    for (size_t k = 0; k < n1 + n2; k++) {
        cpy[k] = array[k];
    }
    while (i + j < n1 + n2) {
        if (i == n1 || (j < n2 && cpy[i] > cpy[n1 + j])) {
            array[i + j] = cpy[n1 + j];
            j++;
            continue;
        }
        array[i + j] = cpy[i];
        i++;
    }
}

void sort_int_array(int *array, size_t n)
{
    if (array == NULL || n == 1)
        return;
    sort_int_array(array, n / 2);
    sort_int_array(array + (n / 2), n - n / 2);
    merge(array, n / 2, n - n / 2);
}