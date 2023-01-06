#include <stdlib.h>
#include "string.module.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *source = this == NULL ? NULL : this->str;
    size_t source_len = this == NULL ? 0 : this->length(this);
    size_t cursor = 0;
    size_t i = 0;

    if (pos >= source_len || source == NULL || str == NULL)
        return (-1);
    source += pos;
    for (; source[i] != '\0'; i++) {
        if (str[cursor] == '\0') {
            break;
        }
        cursor = source[i] == str[cursor] ? cursor + 1 : 0;
    }
    if (str[cursor] == '\0') {
        return (i + pos - cursor);
    }
    return (-1);
}
int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (str == NULL)
        return (-1);
    return (find_c(this, str->str, pos));
}