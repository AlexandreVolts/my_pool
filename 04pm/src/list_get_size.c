#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int output = 0;

    for (; list != NULL; list = list->next, output++);
    return (output);
}
bool list_is_empty(list_t list)
{
    return (list_get_size(list) == 0);
}