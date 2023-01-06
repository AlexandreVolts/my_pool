#include <stdlib.h>
#include "string.module.h"

int to_int(const string_t *this)
{
    char *str = this == NULL ? NULL : this->str;
    int sign = 1;
    int output = 0;

    if (str == NULL)
        return (0);
    for (; (*str < '0' || *str > '9') && *str != '\0'; str++) {
        if (*str == '-')
            sign *= -1;
    }
    for (; *str >= '0' && *str <= '9'; str++) {
        output *= 10;
        output += (*str) - '0';
    }
    return (output * sign);
}