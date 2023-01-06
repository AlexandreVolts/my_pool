#include <stdlib.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_to_int_test, null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.to_int(&s) == 0);
    string_destroy(&s);
}
Test(string_to_int_test, empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert(s.to_int(&s) == 0);
    string_destroy(&s);
}
Test(string_to_int_test, str)
{
    string_t s;

    string_init(&s, "hello world!");
    cr_assert(s.to_int(&s) == 0);
    string_destroy(&s);
}
Test(string_to_int_test, nbr)
{
    string_t s;

    string_init(&s, "586");
    cr_assert(s.to_int(&s) == 586);
    s.assign_c(&s, "-95");
    cr_assert(s.to_int(&s) == -95);
    s.assign_c(&s, "0");
    cr_assert(s.to_int(&s) == 0);
    s.assign_c(&s, "-0");
    cr_assert(s.to_int(&s) == 0);
    string_destroy(&s);
}
Test(string_to_int_test, noisy_nbr)
{
    string_t s;

    string_init(&s, "hello 586 world");
    cr_assert(s.to_int(&s) == 586);
    s.assign_c(&s, "----95---");
    cr_assert(s.to_int(&s) == 95);
    s.assign_c(&s, "that 0 is not a 52");
    cr_assert(s.to_int(&s) == 0);
    s.assign_c(&s, "that ---36 !!is !!not a 52");
    cr_assert(s.to_int(&s) == -36);
    string_destroy(&s);
}