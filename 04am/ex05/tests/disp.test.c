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
    int array[] = { 8, -3, 12, 19 };

    disp_int_array(array, 4);
    cr_assert_stdout_eq_str("8\n-3\n12\n19\n");
}
Test(disp_int_array_test, with_null, .init=redirect_all_stdout)
{
    int *array = NULL;

    disp_int_array(array, 5);
    cr_assert_stdout_eq_str("");
}
Test(disp_array_test, with_int_array, .init=redirect_all_stdout)
{
    int arr[] = { 67, 78, 9 };

    disp_array(arr, 3, sizeof(int), (void *)&my_putnbr);
    cr_assert_stdout_eq_str("67789");
}
Test(disp_array_test, with_str_array, .init=redirect_all_stdout)
{
    char *arr[] = { "hello", "world", "!" };

    disp_array(arr, 3, sizeof(char *), (void *)&my_putstr);
    cr_assert_stdout_eq_str("helloworld!");
}
Test(disp_array_test, with_char_array, .init=redirect_all_stdout)
{
    char arr[] = "hey!";

    disp_array(arr, 4, sizeof(char), (void *)&my_putchar);
    cr_assert_stdout_eq_str("hey!");
}
Test(disp_array_test, with_null_array, .init=redirect_all_stdout)
{
    disp_array(NULL, 0, 0, NULL);
    cr_assert_stdout_eq_str("");
}