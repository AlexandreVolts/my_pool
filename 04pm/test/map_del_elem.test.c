#include <stdlib.h>
#include <criterion/criterion.h>
#include "map.h"
#include "prototypes.h"

Test(map_del_elem_test, empty)
{
    cr_assert(!map_del_elem(NULL, "test", NULL));
}
Test(map_del_elem_test, del_valid_items)
{
    map_t map = NULL;
    int a = 56;
    int b = 36;
    char k1[] = "key";
    char k2[] = "another_key";
    
    map_add_elem(&map, k1, &a, (void *)&strcmp);
    map_add_elem(&map, k2, &b, (void *)&strcmp);
    cr_assert(map_del_elem(&map, "another_key", (void *)&strcmp));
    cr_assert(map_get_size(map) == 1);
    cr_assert(map_del_elem(&map, "key", (void *)&strcmp));
    cr_assert(map_is_empty(map));
}
Test(map_del_elem_test, del_invalid_items)
{
    map_t map = NULL;
    int a = 56;
    int b = 36;
    char k1[] = "key";
    char k2[] = "another_key";

    map_add_elem(&map, k1, &a, (void *)&strcmp);
    map_add_elem(&map, k2, &b, (void *)&strcmp);
    cr_assert(!map_del_elem(&map, "test", (void *)&strcmp));
    cr_assert(map_get_size(map) == 2);
    cr_assert(!map_del_elem(&map, "another_test", (void *)&strcmp));
    cr_assert(map_get_size(map) == 2);
    map_clear(&map);
}