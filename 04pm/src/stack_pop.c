#include <stdbool.h>
#include "prototypes.h"
#include "stack.h"

bool stack_pop(stack_t *stack_ptr)
{
    return (list_del_elem_at_back(stack_ptr));
}