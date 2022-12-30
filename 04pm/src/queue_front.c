#include <stdbool.h>
#include "prototypes.h"
#include "queue.h"

void *queue_top(queue_t queue_ptr)
{
    return (list_get_elem_at_front(queue_ptr));
}