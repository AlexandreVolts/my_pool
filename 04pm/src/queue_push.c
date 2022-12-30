#include <stdbool.h>
#include "prototypes.h"
#include "queue.h"

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return (list_add_elem_at_back(queue_ptr, elem));
}