#include <stdlib.h>

char *get(void *array, size_t index, size_t size)
{
    return (*(char **)(array + size * index));
}