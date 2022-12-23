#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "prototypes.h"

static int intcmp(int a, int b)
{
    return (a - b);
}
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
    cr_assert(uniq_int_array(NULL, 5) == 0);
}

Test(uniq_array_test, no_uniq_int)
{
    int array[] = { 8, 3, 12, 19 };
    int expect[] = { 8, 3, 12, 19 };

    cr_assert(uniq_array(array, 4, sizeof(int), (void *)&intcmp) == 4);
    for (int i = 0; i < 4; i++) {
        cr_assert(array[i] == expect[i]);
    }
}
Test(uniq_array_test, no_uniq_str)
{
    char *array[] = { "hello", "world", "!!" };
    char *expect[] = { "hello", "world", "!!" };

    cr_assert(uniq_array(array, 3, sizeof(char *), (void *)&strcmp) == 3);
    for (int i = 0; i < 3; i++) {
        cr_assert(strcmp(array[i], expect[i]) == 0);
    }
}
Test(uniq_array_test, some_uniq_int)
{
    int array[] = { 5, 8, 5, 5, 8, 6 };
    int expect[] = { 5, 8, 6 };

    cr_assert(uniq_array(array, 6, sizeof(int), (void *)&intcmp) == 3);
    for (int i = 0; i < 3; i++) {
        cr_assert(array[i] == expect[i]);
    }
}
Test(uniq_array_test, some_uniq_str)
{
    char *array[] = { "do", "re", "mi", "la", "re", "la", "sol" };
    char *expect[] = { "do", "re", "mi", "la", "sol" };

    cr_assert(uniq_array(array, 7, sizeof(char *), (void *)&strcmp) == 5);
    for (int i = 0; i < 5; i++) {
        cr_assert(strcmp(array[i], expect[i]) == 0);
    }
}
Test(uniq_array_test, all_same_int)
{
    int array[] = { 3, 3, 3, 3 };
    int expect[] = { 3 };

    cr_assert(uniq_array(array, 4, sizeof(int), (void *)&intcmp) == 1);
    cr_assert(array[0] == expect[0]);
}
Test(uniq_array_test, all_same_str)
{
    char *array[] = { "do", "do", "do", "do", "do" };
    char *expect[] = { "do" };

    cr_assert(uniq_array(array, 5, sizeof(char *), (void *)&strcmp) == 1);
    cr_assert(strcmp(array[0], expect[0]) == 0);
}
Test(uniq_array_test, with_null)
{
    cr_assert(uniq_array(NULL, 5, 0, NULL) == 0);
}