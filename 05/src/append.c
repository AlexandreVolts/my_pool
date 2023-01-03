#include <stdlib.h>
#include "string.module.h"

void append_c(string_t *this, const char *source)
{
    char *cpy = NULL;
    int len = 0;
    int i = 0;

    if (this == NULL || source == NULL)
        return;
    cpy = this->str;
    len = _strlen(source) + _strlen(cpy);
    this->str = malloc((len + 1) * sizeof(char));
    if (cpy != NULL) {
        for (; cpy[i] != '\0'; i++) {
            this->str[i] = cpy[i];
        }
        free(cpy);
    }
    for (int j = 0; source[j] != '\0'; j++) {
        this->str[i + j] = source[j];
    }
    this->str[len] = '\0';
}
void append_s(string_t *this, const string_t *source)
{
    if (source == NULL)
        return;
    this->append_c(this, source->str);
}