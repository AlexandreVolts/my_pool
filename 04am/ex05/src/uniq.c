#include <stdlib.h>
#include "prototypes.h"

static void remove(void *array, size_t index, size_t n, size_t size)
{
    for (size_t i = index + 1; i < n; i++) {
        set(array, i - 1, size, get(array, i, size));
    }
}
static int intcmp(int a, int b)
{
    return (a - b);
}

size_t uniq_int_array(int *array, size_t n)
{
    return (uniq_array(array, n, sizeof(int), (void *)&intcmp));
}
size_t uniq_array(void *array, size_t n, size_t size, cmp_callback_t compar)
{
    size_t output = n;

    if (array == NULL || compar == NULL)
        return (0);
    for (size_t i = 0; i < output; i++) {
        for (size_t j = i + 1; j < output; j++) {
            if (compar(get(array, i, size), get(array, j, size)) != 0) {
                continue;
            }
            remove(array, j, output, size);
            j--;
            output--;
        }
    }
    return (output);
}