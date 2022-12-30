#include <stdlib.h>
#include <criterion/criterion.h>
#include "list.h"
#include "prototypes.h"

static void add_elem_at_list(list_t *list, int *array, int size)
{
    for (int i = 0; i < size; i++) {
        list_add_elem_at_back(list, array + i);
    }
}

Test(list_del_elem_at_position_test, del_at_front)
{
    list_t list = NULL;
    int arr[] = { 8, 43, -98 };

    add_elem_at_list(&list, arr, 3);
    cr_assert(list_del_elem_at_front(&list));
    cr_assert(list_get_size(list) == 2);
    cr_assert(*((const int *)list_get_elem_at_front(list)) == 43);
    list_clear(&list);
}
Test(list_del_elem_at_position_test, del_at_front_empty_list)
{
    cr_assert(!list_del_elem_at_front(NULL));
}
Test(list_del_elem_at_position_test, del_at_position)
{
    list_t list = NULL;
    int arr[] = { 8, 22, 43, -98 };

    add_elem_at_list(&list, arr, 4);
    cr_assert(list_del_elem_at_position(&list, 1));
    cr_assert(list_get_size(list) == 3);
    cr_assert(*((const int *)list_get_elem_at_position(list, 1)) == 43);
    cr_assert(list_del_elem_at_position(&list, 0));
    cr_assert(list_get_size(list) == 2);
    cr_assert(*((const int *)list_get_elem_at_position(list, 0)) == 43);
    list_clear(&list);
}
Test(list_del_elem_at_position_test, del_at_invalid_position)
{
    list_t list = NULL;
    int arr[] = { 8, -98 };

    add_elem_at_list(&list, arr, 2);
    cr_assert(!list_del_elem_at_position(&list, 5));
    list_clear(&list); 
}
Test(list_del_elem_at_position_test, del_at_position_empty_list)
{
    cr_assert(!list_del_elem_at_position(NULL, 5));
}
Test(list_del_elem_at_position_test, del_at_back)
{
    list_t list = NULL;
    int arr[] = { 8, -98 };

    add_elem_at_list(&list, arr, 2);
    cr_assert(list_del_elem_at_back(&list));
    cr_assert(list_get_size(list) == 1);
    cr_assert(*((const int *)list_get_elem_at_front(list)) == 8);
    list_clear(&list);
}
Test(list_del_elem_at_position_test, del_at_back_empty_list)
{
    cr_assert(!list_del_elem_at_back(NULL));
}