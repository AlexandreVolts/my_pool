#include <stdlib.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_compare_test, both_null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.compare_c(&s, NULL) == 0);
    string_destroy(&s);
}
Test(string_compare_test, str_null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.compare_c(&s, "str") == -'s');
    string_destroy(&s);
}
Test(string_compare_test, source_null)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert(s.compare_c(&s, NULL) == 'H');
    string_destroy(&s);
}
Test(string_compare_test, both_valid_str)
{
    string_t s;

    string_init(&s, "THIS is a TEST");
    cr_assert(s.compare_c(&s, "") == 'T');
    cr_assert(s.compare_c(&s, " ") == ('T' - ' '));
    cr_assert(s.compare_c(&s, "THIS is invalid") == ('a' - 'i'));
    cr_assert(s.compare_c(&s, "THIS is") == ' ');
    cr_assert(s.compare_c(&s, "THIS is a TEST") == 0);
    string_destroy(&s);
}