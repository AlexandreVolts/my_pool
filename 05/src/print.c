#include <stdlib.h>
#include <unistd.h>
#include "string.module.h"

void print(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    write(1, this->str, this->length(this));
}