#include <stdbool.h>
#include <stdlib.h>
#include "map.h"
#include "prototypes.h"

bool map_add_elem(map_t *map_ptr, void *key, void *value, key_comparator_t key_cmp)
{
    pair_t *pair = malloc(sizeof(pair_t));
    map_t map = *map_ptr;
    int index = map_get_index(map, key, key_cmp);

    pair->key = key;
    pair->value = value;
    if (index == -1)
        return (list_add_elem_at_front(map_ptr, pair));
    free(pair);
    for (; index > 0; index--, map = map->next);
    pair = map->value;
    pair->value = value;
    return (true);
}