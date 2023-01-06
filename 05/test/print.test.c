#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "string.module.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(string_print, null, .init=redirect_all_stdout)
{
    string_t s;

    string_init(&s, NULL);
    s.print(&s);
    cr_assert_stdout_eq_str("");
    string_destroy(&s);
}
Test(string_print, empty, .init=redirect_all_stdout)
{
    string_t s;

    string_init(&s, "");
    s.print(&s);
    cr_assert_stdout_eq_str("");
    string_destroy(&s);
}
Test(string_print, str, .init=redirect_all_stdout)
{
    string_t s;

    string_init(&s, "hello!");
    s.print(&s);
    cr_assert_stdout_eq_str("hello!");
    string_destroy(&s);
}