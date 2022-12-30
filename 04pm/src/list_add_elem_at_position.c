#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "prototypes.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *node = malloc(sizeof(node_t));

    if (front_ptr == NULL || node == NULL) {
        free(node);
        return (false);
    }
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return (true);
}
bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int position)
{
    list_t list;
    list_t next;

    if (front_ptr == NULL || *front_ptr == NULL || position == 0) {
        return (list_add_elem_at_front(front_ptr, elem));
    }
    list = *front_ptr;
    for (unsigned int i = 1; i < position && list != NULL; i++) {
        list = list->next;
    }
    next = list->next;
    list->next = malloc(sizeof(node_t));
    list->next->value = elem;
    list->next->next = next;
    return (true);
}
bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    unsigned int size = list_get_size(front_ptr == NULL ? NULL : *front_ptr);

    return (list_add_elem_at_position(front_ptr, elem, size));
}