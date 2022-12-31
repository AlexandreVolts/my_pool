#include <stdlib.h>
#include <criterion/criterion.h>
#include "map.h"
#include "prototypes.h"

static pair_t create_pair(void *key, void *value)
{
    pair_t pair;

    pair.key = key;
    pair.value = value;
    return (pair);
}
Test(map_get_index_test, empty)
{
    cr_assert(map_get_index(NULL, "key", NULL) == -1);
}
Test(map_get_index_test, valid_key)
{
    map_t map = NULL;
    int a = 56;
    int b = 36;
    pair_t p1 = create_pair("key", &a);
    pair_t p2 = create_pair("another_key", &b);

    list_add_elem_at_back(&map, &p1);
    list_add_elem_at_back(&map, &p2);
    cr_assert(map_get_index(map, "key", (void *)&strcmp) == 0);
    cr_assert(map_get_index(map, "another_key", (void *)&strcmp) == 1);
    list_clear(&map);
}
Test(map_get_index_test, invalid_key)
{
    map_t map = NULL;
    int a = 56;
    int b = 36;
    pair_t p1 = create_pair("key", &a);
    pair_t p2 = create_pair("another_key", &b);

    list_add_elem_at_back(&map, &p1);
    list_add_elem_at_back(&map, &p2);
    cr_assert(map_get_index(map, "invalid_key", (void *)&strcmp) == -1);
    list_clear(&map);
}