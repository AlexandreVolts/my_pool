#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "prototypes.h"

static int intcmp(int a, int b)
{
    return (a - b);
}
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
    sort_int_array(NULL, 5);
}

Test(sort_array_test, not_sorted_int)
{
    int array[] = { 8, 3, 12, 19, 3 };
    int expect[] = { 3, 3, 8, 12, 19 };

    sort_array(array, 5, sizeof(int), (void *)&intcmp);
    for (int i = 0; i < 5; i++) {
        cr_assert(array[i] == expect[i]);
    }
}
Test(sort_array_test, not_sorted_str)
{
    char *array[] = { "A", "test", "Fine" };
    char *expect[] = { "A", "Fine", "test" };

    sort_array(array, 3, sizeof(char *), (void *)&strcmp);
    for (int i = 0; i < 3; i++) {
        cr_assert(strcmp(array[i], expect[i]));
    }
}
Test(sort_array_test, already_sorted_int)
{
    int array[] = { 4, 8, 25, 45, 68, 78 };
    int expect[] = { 4, 8, 25, 45, 68, 78 };

    sort_array(array, 6, sizeof(int), (void *)&intcmp);
    for (int i = 0; i < 6; i++) {
        cr_assert(array[i] == expect[i]);
    }
}
Test(sort_array_test, already_sorted_str)
{
    char *array[] = { "A", "Nice", "sorted", "string" };
    char *expect[] = { "A", "Nice", "sorted", "string" };

    sort_array(array, 4, sizeof(char *), (void *)strcmp);
    for (int i = 0; i < 4; i++) {
        cr_assert(strcmp(array[i], expect[i]));
    }
}
Test(sort_array_test, with_null)
{
    sort_array(NULL, 5, 0, NULL);
}