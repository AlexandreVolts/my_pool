#include <stdbool.h>
#include "prototypes.h"
#include "stack.h"

void *stack_top(stack_t stack_ptr)
{
    return (list_get_elem_at_back(stack_ptr));
}