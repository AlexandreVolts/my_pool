#include <stdbool.h>
#include "prototypes.h"
#include "map.h"

unsigned int map_get_size(map_t map)
{
    return (list_get_size(map));
}
bool map_is_empty(map_t map)
{
    return (list_is_empty(map));
}