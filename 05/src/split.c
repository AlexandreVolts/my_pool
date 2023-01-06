#include <stdlib.h>
#include "string.module.h"

static size_t get_array_len(char **array)
{
    size_t i = 0;

    for (; array != NULL && array[i] != NULL; i++);
    return (i);
}
static size_t get_splits(const char *str, char separator)
{
    size_t output = 0;

    if (str == NULL || *str == '\0')
        return (0);
    for (; *str == separator; str++);
    for (; *str != '\0'; str++) {
        if (*str == separator && *str != *(str + 1) && *(str + 1) != '\0')
            output++;
    }
    return (output + 1);
}

char **split_c(const string_t *this, char separator)
{
    char **output;
    size_t len = 0;
    size_t cursor = 0;
    size_t space = 0;
    long int index = 0;
    char buffer[2] = { separator, '\0' };
    
    if (this == NULL)
        return (NULL);
    len = get_splits(this->str, separator);
    output = malloc(sizeof(char *) * (len + 1));
    for (size_t i = 0; i < len; i++) {
        for (; this->str[cursor] == separator; cursor++);
        index = this->find_c(this, buffer, cursor);
        space = (index == -1 ? this->length(this) : (size_t)index) - cursor;
        output[i] = malloc(sizeof(char) * (space + 1));
        cursor += this->copy(this, output[i], space, cursor);
    }
    output[len] = NULL;
    return (output);
}
string_t **split_s(const string_t *this, char separator)
{
    char **chunks = split_c(this, separator);
    string_t **output;
    size_t len = get_array_len(chunks);
    
    if (chunks == NULL)
        return (NULL);
    output = malloc(sizeof(string_t *) * (len + 1));
    for (size_t i = 0; i < len; i++) {
        output[i] = malloc(sizeof(string_t));
        string_init(output[i], chunks[i]);
        free(chunks[i]);
    }
    output[len] = NULL;
    free(chunks);
    return (output);
}