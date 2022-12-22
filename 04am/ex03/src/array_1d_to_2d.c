#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int **output = malloc(height * sizeof(int *));

    if (array == NULL) {
        free(output);
        *res = NULL;
        return;
    }
    for (size_t y = 0; y < height; y++) {
        output[y] = malloc(width * sizeof(int));
        for (size_t x = 0; x < width; x++) {
            output[y][x] = array[y * width + x];
        }
    }
    *res = output;
}
void array_2d_free(int **array, size_t height, size_t width)
{
    if (array == NULL)
        return;
    for (size_t i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}