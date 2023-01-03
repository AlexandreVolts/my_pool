#include <stdlib.h>
#include "string.module.h"

static size_t len(const char *str)
{
    size_t i = 0;

    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}
char at(string_t *this, size_t pos)
{
    if (this == NULL || pos >= len(this->str))
        return (-1);
    return (this->str[pos]);
}