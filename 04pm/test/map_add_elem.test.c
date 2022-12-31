#include <stdlib.h>
#include <criterion/criterion.h>
#include "map.h"
#include "prototypes.h"

Test(map_add_elem_test, add_values)
{
    map_t map = NULL;

    cr_assert(map_add_elem(&map, "key", "value", (void*)&strcmp));
    cr_assert(map_get_size(map) == 1);
    cr_assert(map_add_elem(&map, "another_key", "value", (void*)&strcmp));
    cr_assert(map_get_size(map) == 2);
    map_clear(&map);
}
Test(map_add_elem_test, add_same_values)
{
    map_t map = NULL;

    cr_assert(map_add_elem(&map, "key", "value", (void*)&strcmp));
    cr_assert(map_get_size(map) == 1);
    cr_assert(map_add_elem(&map, "key", "value", (void*)&strcmp));
    cr_assert(map_get_size(map) == 1);
    map_clear(&map);
}