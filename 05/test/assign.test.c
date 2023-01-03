#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_assign_test, null_str)
{
    string_t s;

    string_init(&s, NULL);
    s.assign_c(&s, NULL);
    cr_assert(s.str == NULL);
}
Test(string_assign_test, undefined_module)
{
    string_t s;

    string_init(&s, "");
    s.assign_c(&s, "Hello world!");
    cr_assert(strcmp(s.str, "Hello world!") == 0);
    string_destroy(&s);
}
Test(string_assign_test, defined_module)
{
    string_t s;

    string_init(&s, "test test");
    s.assign_c(&s, "Hello!");
    cr_assert(strcmp(s.str, "Hello!") == 0);
    string_destroy(&s);
}