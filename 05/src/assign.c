#include <stdlib.h>
#include "string.module.h"

void assign_c(string_t *this, const char *source)
{
    int i = 0;

    if (this == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    if (source == NULL) {
        this->str = NULL;
        return;
    }
    this->str = malloc((_strlen(source) + 1) * sizeof(char));
    for (; source[i] != '\0'; i++) {
        this->str[i] = source[i];
    }
    this->str[i] = '\0';
}
void assign_s(string_t *this, const string_t *source)
{
    if (source == NULL)
        return;
    this->assign_c(this, source->str);
}