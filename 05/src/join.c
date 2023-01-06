#include <stdlib.h>
#include "string.module.h"

void join_c(string_t *this, char delim, const char * const *array)
{
    char buffer[2] = { delim, '\0' };

    if (this == NULL || array == NULL)
        return;
    this->clear(this);
    for (size_t i = 0; array[i] != NULL; i++) {
        this->append_c(this, array[i]);
        if (array[i + 1] != NULL) {
            this->append_c(this, buffer);
        }
    }
}
void join_s(string_t *this, char delim, const string_t * const *array)
{
    char buffer[2] = { delim, '\0' };

    if (this == NULL || array == NULL)
        return;
    this->clear(this);
    for (size_t i = 0; array[i] != NULL; i++) {
        this->append_s(this, array[i]);
        if (array[i + 1] != NULL) {
            this->append_c(this, buffer);
        }
    }
}