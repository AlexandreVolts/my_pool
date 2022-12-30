#include <stdbool.h>
#include "prototypes.h"
#include "queue.h"

bool queue_pop(queue_t *queue_ptr)
{
    return (list_del_elem_at_back(queue_ptr));
}