#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "prototypes.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t list = front_ptr == NULL ? NULL : *front_ptr;

    if (list == NULL)
        return (false);
    *front_ptr = list->next;
    free(list);
    return (true);
}
bool list_del_elem_at_back(list_t *front_ptr)
{
    unsigned int size = list_get_size(front_ptr == NULL ? NULL : *front_ptr);

    return (list_del_elem_at_position(front_ptr, size - 1));
}
bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t list = front_ptr == NULL ? NULL : *front_ptr;
    node_t *tmp_node;

    if (list == NULL)
        return (false);
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    for (; list != NULL && position > 1; position--, list = list->next);
    tmp_node = list == NULL ? NULL : list->next;
    if (tmp_node == NULL)
        return (false);
    list->next = tmp_node->next;
    free(tmp_node);
    return (true);
}