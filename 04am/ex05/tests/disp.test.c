#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

static void redirect_all_stdout()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
Test(disp_int_array_test, with_array, .init=redirect_all_stdout)
{
    int array[] = { 8, 3, 12, 19 };
    int expect[] = { 8, 3, 12, 19 };

    disp_int_array(array, 4);
    cr_assert_stdout_eq_str("8\n3\n12\n19\n");
}
Test(disp_int_array_test, with_null, .init=redirect_all_stdout)
{
    int *array = NULL;

    disp_int_array(array, 5);
    cr_assert_stdout_eq_str("");
}