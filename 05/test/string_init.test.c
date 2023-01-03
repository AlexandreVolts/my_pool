#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_init_test, null_str)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert(s.str == NULL);
}
Test(string_init_test, undefined_module)
{
    string_t s;

    string_init(&s, "hello");
    cr_assert(strcmp(s.str, "hello") == 0);
    string_destroy(&s);
    cr_assert(s.str == NULL);
}
Test(string_init_test, defined_module)
{
    string_t s;

    s.str = "hello";
    string_init(&s, "test test");
    cr_assert(strcmp(s.str, "test test") == 0);
    string_destroy(&s);
    cr_assert(s.str == NULL);
}