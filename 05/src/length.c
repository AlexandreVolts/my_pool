#include <stdlib.h>
#include "string.module.h"

int length(string_t *this)
{
    if (this == NULL)
        return (0);
    return (_strlen(this->str));
}