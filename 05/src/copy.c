#include <stdlib.h>
#include "string.module.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    char *source = this == NULL ? NULL : this->str;
    size_t source_len = this == NULL ? 0 : this->length(this);
    size_t i = 0;

    if (source == NULL || s == NULL) {
        return (0);
    }
    for (; i < n && pos + i < source_len; i++) {
        s[i] = source[i + pos];
    }
    s[i] = '\0';
    return (i);
}