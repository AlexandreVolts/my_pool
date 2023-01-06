#include <stdlib.h>
#include "string.module.h"

string_t *slice(const string_t *this, int offset, int length)
{
    string_t *output = malloc(sizeof(string_t));
    size_t refined_length = length < 0 ? (size_t)(-length) : (size_t)length;
    int refined_offset = 0;
    char buffer[refined_length + 1];

    if (this == NULL) {
        free(output);
        return (NULL);
    }
    if (this->str == NULL) {
        string_init(output, NULL);
        return (output);
    }
    refined_offset = offset < 0 ? (int)(this->length(this) + offset) : offset;
    refined_offset += length < 0 ? length : 0;
    refined_length += refined_offset < 0 ? refined_offset : 0;
    refined_offset = refined_offset < 0 ? 0 : refined_offset;
    this->copy(this, buffer, refined_length, (size_t)refined_offset);
    string_init(output, buffer);
    return (output);
}