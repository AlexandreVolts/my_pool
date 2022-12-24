#include <stdlib.h>
#include <criterion/criterion.h>
#include "list.h"
#include "prototypes.h"

Test(list_add_elem_at_position_test, add_at_front)
{
    list_t list = NULL;
    int i = 8, j = 43, k = -98;

    cr_assert(list_add_elem_at_front(&list, &i));
    cr_assert(list_add_elem_at_front(&list, &j));
    cr_assert(list_add_elem_at_front(&list, &k));
    cr_assert(*((const int *)list->value) == -98);
    cr_assert(*((const int *)list->next->value) == 43);
    cr_assert(*((const int *)list->next->next->value) == 8);
    cr_assert(list_get_size(list) == 3);
    list_clear(&list);
}
Test(list_add_elem_at_position_test, add_at_back)
{
    list_t list = NULL;
    int i = 8, j = 22, k = 43, m = -98;

    cr_assert(list_add_elem_at_back(&list, &i));
    cr_assert(list_add_elem_at_back(&list, &j));
    cr_assert(list_add_elem_at_back(&list, &k));
    cr_assert(list_add_elem_at_back(&list, &m));
    cr_assert(*((const int *)list->value) == 8);
    cr_assert(*((const int *)list->next->value) == 22);
    cr_assert(*((const int *)list->next->next->value) == 43);
    cr_assert(*((const int *)list->next->next->next->value) == -98);
    cr_assert(list_get_size(list) == 4);
    list_clear(&list);
}
Test(list_add_elem_at_position_test, add_at_position)
{
    list_t list = NULL;
    int i = 8, j = 22, k = 43, m = -98;

    cr_assert(list_add_elem_at_back(&list, &i));
    cr_assert(list_add_elem_at_back(&list, &j));
    cr_assert(list_add_elem_at_position(&list, &k, 1));
    cr_assert(list_add_elem_at_position(&list, &m, 1));
    cr_assert(*((const int *)list->value) == 8);
    cr_assert(*((const int *)list->next->value) == -98);
    cr_assert(*((const int *)list->next->next->value) == 43);
    cr_assert(*((const int *)list->next->next->next->value) == 22);
    cr_assert(list_get_size(list) == 4);
    list_clear(&list);
}