#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res);
void array_2d_free(int **array, size_t height, size_t width);

#endif