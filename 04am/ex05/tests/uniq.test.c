#include <stdlib.h>
#include <criterion/criterion.h>
#include "prototypes.h"

Test(uniq_int_array_test, no_uniq)
{
    int array[] = { 8, 3, 12, 19 };
    int expect[] = { 8, 3, 12, 19 };

    cr_assert(uniq_int_array(array, 4) == 4);
    for (int i = 0; i < 4; i++) {
        cr_assert(array[i] == expect[i]);
    }
}
Test(uniq_int_array_test, some_uniq)
{
    int array[] = { 5, 8, 5, 5, 8, 6 };
    int expect[] = { 5, 8, 6 };

    cr_assert(uniq_int_array(array, 6) == 3);
    for (int i = 0; i < 3; i++) {
        cr_assert(array[i] == expect[i]);
    }
}
Test(uniq_int_array_test, all_same)
{
    int array[] = { 3, 3, 3, 3 };
    int expect[] = { 3 };

    cr_assert(uniq_int_array(array, 4) == 1);
    cr_assert(array[0] == expect[0]);
}
Test(uniq_int_array_test, with_null)
{
    int *array = NULL;

    cr_assert(uniq_int_array(array, 5) == 0);
    cr_assert(array == NULL);
}