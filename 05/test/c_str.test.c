#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_c_str_test, null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.c_str(&s) == NULL);
    string_destroy(&s);
}
Test(string_c_str_test, empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert(strcmp(s.c_str(&s), "") == 0);
    cr_assert(s.str == s.c_str(&s));
    string_destroy(&s);
}
Test(string_c_str_test, valid_str)
{
    string_t s;

    string_init(&s, "this is a test");
    cr_assert(strcmp(s.c_str(&s), "this is a test") == 0);
    cr_assert(s.str == s.c_str(&s));
    string_destroy(&s);
}