#include <stdlib.h>
#include "list.h"
#include "prototypes.h"

void *list_get_elem_at_front(list_t list)
{
    return (list == NULL ? NULL : list->value);
}
void *list_get_elem_at_back(list_t list)
{
    unsigned int size = list_get_size(list);

    return (list_get_elem_at_position(list, size - 1));
}
void *list_get_elem_at_position(list_t list, unsigned int position)
{
    for (; list != NULL && position > 0; position--, list = list->next);
    return (list == NULL ? NULL : list->value);
}