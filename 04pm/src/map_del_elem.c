#include <stdlib.h>
#include "map.h"
#include "prototypes.h"

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t map = map_ptr != NULL ? *map_ptr : NULL;
    pair_t *pair;
    int index = map_get_index(map, key, key_cmp);

    if (index == -1)
        return (false);
    pair = list_get_elem_at_position(map, index);
    if (pair == NULL || !list_del_elem_at_position(map_ptr, index))
        return (false);
    free(pair);
    return (true);
}