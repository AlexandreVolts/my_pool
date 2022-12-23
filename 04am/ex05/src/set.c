#include <stdlib.h>
#include <string.h>

void set(void *array, size_t index, size_t size, void *value)
{
    size_t offset = index * size;
    void *position = (char*)array + offset;

    memcpy(position, value, size);
}