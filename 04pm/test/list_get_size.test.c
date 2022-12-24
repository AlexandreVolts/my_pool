#include <stdlib.h>
#include <criterion/criterion.h>
#include "list.h"
#include "prototypes.h"

Test(list_get_size_test, empty)
{
    list_t list = NULL;

    cr_assert(list_is_empty(list));
}
Test(list_get_size_test, not_empty)
{
    list_t list = NULL;
    list_t tmp = NULL;
    unsigned int expected_size = 8;

    for (unsigned int i = 0; i < expected_size; i++) {
        list = malloc(sizeof(node_t));
        list->next = tmp;
        list->value = 0;
        tmp = list;
    }
    cr_assert(list_get_size(list) == 8);
    cr_assert(!list_is_empty(list));
    list_clear(&list);
}