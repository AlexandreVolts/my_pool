#include <stdlib.h>
#include "prototypes.h"
#include "map.h"

void map_clear(map_t *map_ptr)
{
    map_t map = map_ptr != NULL ? *map_ptr : NULL;

    for (; map != NULL; map = map->next) {
        free(map->value);
    }
    return (list_clear(map_ptr));
}