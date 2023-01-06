#include <stdlib.h>
#include "string.module.h"

const char *c_str(const string_t *this)
{
    return (this == NULL ? NULL : this->str);
}