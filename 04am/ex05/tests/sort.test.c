#include <stdlib.h>
#include <criterion/criterion.h>
#include "prototypes.h"

Test(sort_int_array_test, not_sorted)
{
    int array[] = { 8, 3, 12, 19, 3 };
    int expect[] = { 3, 3, 8, 12, 19 };

    sort_int_array(array, 5);
    for (int i = 0; i < 5; i++) {
        cr_assert(array[i] == expect[i]);
    }
}
Test(sort_int_array_test, already_sorted)
{
    int array[] = { 4, 8, 25, 45, 68, 78 };
    int expect[] = { 4, 8, 25, 45, 68, 78 };

    sort_int_array(array, 6);
    for (int i = 0; i < 6; i++) {
        cr_assert(array[i] == expect[i]);
    }

}
Test(sort_int_array_test, with_null)
{
    int *array = NULL;

    sort_int_array(array, 5);
    cr_assert(array == NULL);
}