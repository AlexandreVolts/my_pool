#include <stdlib.h>
#include "string.module.h"

void string_destroy(string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    free(this->str);
    this->str = NULL;
}