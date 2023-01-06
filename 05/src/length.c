#include <stdlib.h>
#include "string.module.h"

size_t length(const string_t *this)
{
    if (this == NULL)
        return (0);
    return (_strlen(this->str));
}
int empty(const string_t *this)
{
    return (this == NULL ? 0 : this->length(this) == 0);
}