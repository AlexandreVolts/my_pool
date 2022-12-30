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
Test(list_get_elem_at_position_test, get_at_front_one_elem)
{
    list_t list = NULL;
    int i = -42;

    list_add_elem_at_back(&list, &i);
    cr_assert(*((const int *)list_get_elem_at_front(list)) == -42);
    list_clear(&list);
}
Test(list_get_elem_at_position_test, get_at_front)
{
    list_t list = NULL;
    int arr[] = { 52, 43 };

    add_elem_at_list(&list, arr, 2);
    cr_assert(*((const int *)list_get_elem_at_front(list)) == 52);
    list_clear(&list);
}
Test(list_get_elem_at_position_test, get_invalid_front)
{
    cr_assert(list_get_elem_at_front(NULL) == NULL);
}
Test(list_get_elem_at_position_test, get_at_position)
{
    list_t list = NULL;
    int arr[] = { 8, 43, -98 };

    add_elem_at_list(&list, arr, 3);
    cr_assert(*((const int *)list_get_elem_at_position(list, 1)) == 43);
    cr_assert(*((const int *)list_get_elem_at_position(list, 2)) == -98);
    cr_assert(*((const int *)list_get_elem_at_position(list, 0)) == 8);
    list_clear(&list);
}
Test(list_get_elem_at_position_test, get_invalid_position)
{
    list_t list = NULL;
    int i = 8;

    list_add_elem_at_back(&list, &i);
    cr_assert(list_get_elem_at_position(list, 1) == NULL);
    list_clear(&list);
}
Test(list_get_elem_at_position_test, get_at_back_one_elem)
{
    list_t list = NULL;
    int i = 8;

    list_add_elem_at_back(&list, &i);
    cr_assert(*((const int *)list_get_elem_at_back(list)) == 8);
    list_clear(&list);
}
Test(list_get_elem_at_position_test, get_at_back)
{
    list_t list = NULL;
    int arr[] = { 8, 22 };

    add_elem_at_list(&list, arr, 2);
    cr_assert(*((const int *)list_get_elem_at_back(list)) == 22);
    list_clear(&list);
}
Test(list_get_elem_at_position_test, get_invalid_back)
{
    cr_assert(list_get_elem_at_back(NULL) == NULL);
}