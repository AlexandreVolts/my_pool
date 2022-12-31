#include <stdlib.h>
#include "map.h"
#include "prototypes.h"

void *map_get_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    list_t elem = map_ptr != NULL ? *map_ptr : NULL;
    int index = map_get_index(elem, key, key_cmp);
    pair_t *pair;
    
    if (index == -1)
        return (NULL);
    elem = list_get_elem_at_position(elem, index);
    pair = elem != NULL ? elem->value : NULL;
    return (pair != NULL ? pair->value : NULL);
}
