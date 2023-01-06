#include <stdlib.h>

size_t _strlen(const char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}