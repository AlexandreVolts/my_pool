#include <stdlib.h>
#include <criterion/criterion.h>
#include "list.h"
#include "prototypes.h"

Test(list_clear_test, already_empty)
{
    list_t list = NULL;

    list_clear(&list);
    cr_assert(list == NULL);
}
Test(list_clear_list, not_empty)
{
    list_t list = NULL;
    list_t tmp = NULL;
    unsigned int expected_size = 5;

    for (unsigned int i = 0; i < expected_size; i++) {
        list = malloc(sizeof(node_t));
        list->next = tmp;
        list->value = 0;
        tmp = list;
    }
    list_clear(&list);
    cr_assert(list == NULL);
    cr_assert(list_is_empty(list));
}