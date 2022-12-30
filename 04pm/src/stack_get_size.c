#include <stdbool.h>
#include "prototypes.h"
#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return (list_get_size(stack));
}
bool stack_is_empty(stack_t stack)
{
    return (list_is_empty(stack));
}