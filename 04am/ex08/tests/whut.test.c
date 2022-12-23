#include <stdlib.h>
#include <criterion/criterion.h>
#include "prototypes.h"

Test(get_array_nb_elem_test, basic_array)
{
    int arr[1000] = { 0 };

    cr_assert(get_array_nb_elem(&arr[50], &arr[685]) == 635);
}
Test(get_array_nb_elem_test, reverse)
{
    int arr[800] = { 0 };

    cr_assert(get_array_nb_elem(&arr[685], &arr[50]) == 0);
}
Test(get_array_nb_elem_test, one_null)
{
    int arr[5] = { 0 };

    cr_assert(get_array_nb_elem(NULL, &arr[3]) == 0);
}
Test(get_array_nb_elem_test, two_null)
{
    cr_assert(get_array_nb_elem(NULL, NULL) == 0);
}
Test(get_whut_ptr_test, null_array)
{
    whut_t w = { 0 };

    cr_assert(&w == get_whut_ptr(&w.member));
}