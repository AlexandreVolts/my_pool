#include "prototypes.h"
#include "stack.h"

void stack_clear(stack_t *stack_ptr)
{
    return (list_clear(stack_ptr));
}