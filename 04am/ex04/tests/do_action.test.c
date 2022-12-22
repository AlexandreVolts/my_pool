#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "action.h"
#include "prototypes.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(do_action_print_normal_test, with_str, .init=redirect_all_stdout)
{
    do_action(PRINT_NORMAL, "hello world!");
    cr_assert_stdout_eq_str("hello world!");
}
Test(do_action_print_reverse_test, with_str, .init=redirect_all_stdout)
{
    do_action(PRINT_REVERSE, "hello world!");
    cr_assert_stdout_eq_str("!dlrow olleh");
}
Test(do_action_print_upper_test, with_str, .init=redirect_all_stdout)
{
    do_action(PRINT_UPPER, "hello world!");
    cr_assert_stdout_eq_str("HELLO WORLD!");
}
Test(do_action_print_42_test, with_str, .init=redirect_all_stdout)
{
    do_action(PRINT_42, "hello world!");
    cr_assert_stdout_eq_str("42");
}