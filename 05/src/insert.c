#include <stdlib.h>
#include "string.module.h"

void insert_c(string_t *this, const char *str, size_t pos)
{
    char *source = this == NULL ? NULL : this->str;

    if (this == NULL || str == NULL)
        return;
    if (this->str == NULL || pos >= this->length(this)) {
        this->append_c(this, str);
        return;
    }
    this->str = malloc((pos + 1) * sizeof(char));
    for (size_t i = 0; i < pos; i++) {
        this->str[i] = source[i];
    }
    this->str[pos] = '\0';
    this->append_c(this, str);
    this->append_c(this, source + pos);
    free(source);
}
void insert_s(string_t *this, const string_t *str, size_t pos)
{
    if (str == NULL)
        return;
    insert_c(this, str->str, pos);
}