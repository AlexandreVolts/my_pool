#include <stdlib.h>
#include "concat.h"

static int my_strlen(const char *str)
{
    int output = 0;

    for (;str != NULL && *str != '\0'; str++, output++);
    return (output);
}
void concat_strings(const char *str1, const char *str2, char **res)
{
    char *output = malloc(my_strlen(str1) + my_strlen(str2) + 1);
    int index = 0;

    if (str1 == NULL && str2 == NULL) {
        free(output);
        *res = NULL;
        return;
    }
    for (; str1 != NULL && *str1 != '\0'; str1++, index++) {
        output[index] = *str1;
    }
    for (; str2 != NULL && *str2 != '\0'; str2++, index++) {
        output[index] = *str2;
    }
    output[index] = '\0';
    *res = output;
}
void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}