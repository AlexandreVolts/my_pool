#include <stdlib.h>

static void remove(int *array, size_t n, size_t index)
{
    for (size_t i = index + 1; i < n; i++) {
        array[i - 1] = array[i];
    }
    array[n - 1] = 0;
}
size_t uniq_int_array(int *array, size_t n)
{
    size_t output = n;

    if (array == NULL)
        return (0);
    for (size_t i = 0; i < output; i++) {
        for (size_t j = i + 1; j < output; j++) {
            if (array[i] != array[j]) {
                continue;
            }
            remove(array, output, j);
            j--;
            output--;
        }
    }
    return (output);
}