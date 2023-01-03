#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "string.module.h"

Test(string_clear_test, null)
{
    string_t s;

    string_init(&s, NULL);
    s.clear(&s);
    cr_assert(strcmp(s.str, "") == 0);
    string_destroy(&s);
}
Test(string_clear_test, empty)
{
    string_t s;

    string_init(&s, "");
    s.clear(&s);
    cr_assert(strcmp(s.str, "") == 0);
    string_destroy(&s);
}
Test(string_clear_test, str)
{
    string_t s;

    string_init(&s, "hello world!");
    s.clear(&s);
    cr_assert(strcmp(s.str, "") == 0);
    string_destroy(&s);
}