#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

static void merge(void *array, size_t n, size_t size, cmp_callback_t compar)
{
    size_t n1 = n / 2;
    size_t n2 = n - n / 2;
    size_t i = 0;
    size_t j = 0;
    char cpy[size * (n1 + n2)];

    memcpy(cpy, array, size * n);
    while (i + j < n) {
        if (i == n1 || (j < n2 && compar(get(cpy, i, size), get(cpy, n1 + j, size)))) {
            set(array, i + j, size, get(cpy, n1 + j, size));
            j++;
            continue;
        }
        set(array, i + j, size, get(cpy, i, size));
        i++;
    }
}
static int intcmp(int a, int b)
{
    return (a - b);
}

void sort_int_array(int *array, size_t n)
{
    sort_array(array, n, sizeof(int), (void*)&intcmp);
}
void sort_array(void *array, size_t n, size_t size, cmp_callback_t compar)
{
    if (array == NULL || compar == NULL || n == 1) {
        return;
    }
    sort_array((char *)array, n / 2, size, compar);
    sort_array((char *)array + (size * (n / 2)), n - n / 2, size, compar);
    merge(array, n, size, compar);
}