#include "prototypes.h"
#include "queue.h"

void queue_clear(queue_t *queue_ptr)
{
    return (list_clear(queue_ptr));
}