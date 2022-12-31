#include <stdlib.h>
#include "map.h"

int map_get_index(map_t map, void *key, key_comparator_t key_cmp)
{
    pair_t *pair = NULL;
    
    if (key_cmp == NULL)
        return (-1);
    for (int i = 0; map != NULL; i++, map = map->next) {
        pair = map->value;
        if (key_cmp(key, pair->key) == 0)
            return (i);
    }
    return (-1);
}