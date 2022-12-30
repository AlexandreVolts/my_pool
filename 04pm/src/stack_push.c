#include <stdbool.h>
#include "prototypes.h"
#include "stack.h"

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return (list_add_elem_at_back(stack_ptr, elem));
}