#include <stdlib.h>
#include "string.module.h"

int compare_c(string_t *this, const char *source)
{
    char *str = this == NULL ? NULL : this->str;
    int i = 0;

    if (str == NULL && source == NULL)
        return (0);
    if (str == NULL) {
        return (-source[0]);
    }
    if (source == NULL) {
        return (str[0]);
    }
    for (; str[i] != '\0' && source[i] != '\0' && source[i] == str[i]; i++);
    return (str[i] - source[i]);
}
int compare_s(string_t *this, const string_t *source)
{
    return (compare_c(this, source == NULL ? NULL : source->str));
}