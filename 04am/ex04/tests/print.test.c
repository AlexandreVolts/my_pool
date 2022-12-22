#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

static void redirect_all_stdout()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(print_normal_test, with_str, .init=redirect_all_stdout)
{
    print_normal("hello world!");
    cr_assert_stdout_eq_str("hello world!");
}
Test(print_normal_test, with_null, .init=redirect_all_stdout)
{
    print_normal(NULL);
    cr_assert_stdout_eq_str("");
}
Test(print_reverse_test, with_str, .init=redirect_all_stdout)
{
    print_reverse("hello world!");
    cr_assert_stdout_eq_str("!dlrow olleh");
}
Test(print_reverse_test, with_null, .init=redirect_all_stdout)
{
    print_reverse(NULL);
    cr_assert_stdout_eq_str("");
}
Test(print_upper_test, with_str, .init=redirect_all_stdout)
{
    print_upper("hello world!");
    cr_assert_stdout_eq_str("HELLO WORLD!");
}
Test(print_upper_test, with_upper_str, .init=redirect_all_stdout)
{
    print_upper("HELLO!");
    cr_assert_stdout_eq_str("HELLO!");
}
Test(print_upper_test, with_null, .init=redirect_all_stdout)
{
    print_upper(NULL);
    cr_assert_stdout_eq_str("");
}
Test(print_42_test, with_str, .init=redirect_all_stdout)
{
    print_42("hello world!");
    cr_assert_stdout_eq_str("42");
}
Test(print_42_test, with_null, .init=redirect_all_stdout)
{
    print_42(NULL);
    cr_assert_stdout_eq_str("42");
}