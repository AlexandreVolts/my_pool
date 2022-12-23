#include <criterion/criterion.h>
#include "prototypes.h"

Test(pyramid_path_test, with_array)
{
    unsigned int row0[] = { 0 };
    unsigned int row1[] = { 7, 4 };
    unsigned int row2[] = { 2, 3, 6 };
    unsigned int row3[] = { 8, 5, 9, 3 };
    unsigned int *array[] = { row0, row1, row2, row3 };

    cr_assert(pyramid_path(4, (unsigned int **)array) == 12);
}
Test(pyramid_path_test, with_null)
{
    cr_assert(pyramid_path(0, NULL) == 0);
}